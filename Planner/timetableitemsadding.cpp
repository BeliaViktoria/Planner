#include "timetableitemsadding.h"
#include "ui_timetableitemsadding.h"
#include "currentuser.h"

TimetableItemsAdding::TimetableItemsAdding(int lesson, int day) :
    QWidget(nullptr),
    ui(new Ui::TimetableItemsAdding),
    subject(), teacher(), repeating(NULLTYPE)
{
    ui->setupUi(this);
    this->lesson = lesson;
    this->day = day;
    setWindowSettings();
    ui->radioButton_FullWeek->setChecked(true);
    showSubjectsList();
    showTeachersList();
}

TimetableItemsAdding::TimetableItemsAdding(Plan plan) :
    QWidget(nullptr),
    ui(new Ui::TimetableItemsAdding), lesson(plan.getLesson()),
    day(plan.getDay()), subject(plan.getSubject()),
    teacher(plan.getTeacher()), repeating(plan.getRepeating())
{
    ui->setupUi(this);
    setWindowSettings();

    ui->pushButton_Add->setText("Edit");
    ui->label_AddingPlan->setText("Editing plan");

    ui->label_SubjectName->setText(plan.getSubject().getName());
    ui->label_TeacherName->setText(plan.getTeacher().getFullname());
    ui->lineEdit_Room->setText(plan.getRoom());
    ui->lineEdit_Link->setText(plan.getLlink());
    showSubjectsList();
    showTeachersList();

    switch(plan.getRepeating())
    {
    case NULLTYPE:
        ui->radioButton_FullWeek->setChecked(true);
        break;
    case NUMERATOR:
        ui->radioButton_Numerator->setChecked(true);
        break;
    case DENOMINATOR:
        ui->radioButton_Denominator->setChecked(true);
        break;
    }
}

TimetableItemsAdding::~TimetableItemsAdding()
{
    delete ui;
}

void TimetableItemsAdding::setWindowSettings()
{
    hideErrorLabels();
    if(CurrentUser::getInstance()->getSettings().getStartFrom() == NULLTYPE)
    {
        ui->radioButton_Denominator->hide();
        ui->radioButton_Numerator->hide();
        ui->radioButton_FullWeek->hide();
    }
}

bool TimetableItemsAdding::checkFields()
{
    bool status = true;
    hideErrorLabels();
    if(ui->label_SubjectName->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    return status;
}

void TimetableItemsAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_AlreadyTaken->hide();
}

void TimetableItemsAdding::showSubjectsList()
{
    ui->listWidget_Subjects->clear();
    for(Subject& item:CurrentUser::getInstance()->getSubjects())
    {
        ui->listWidget_Subjects->addItem(item.getName());
    }
    hideSubjects();
}

void TimetableItemsAdding::hideSubjects()
{
    if(ui->label_SubjectName->text() != "")
    {
        for(int j = 0; j < ui->listWidget_Subjects->count(); j++)
        {
            ui->listWidget_Subjects->item(j)->setHidden(true);
        }
    }
}

void TimetableItemsAdding::showTeachersList()
{
    ui->listWidget_Teachers->clear();
    for(int i = 0; i < 3; i++)
    {
        if(subject.getTeachers()[i].getFullname() != "")
        {
            ui->listWidget_Teachers->addItem(subject.getTeachers()[i].getFullname());
        }
    }
    hideTeachers();
}

void TimetableItemsAdding::hideTeachers()
{
    if(ui->label_SubjectName->text() == "")
    {
        ui->listWidget_Teachers->clear();
        return;
    }
    if(ui->label_TeacherName->text() != "")
    {
        for(int j = 0; j < ui->listWidget_Teachers->count(); j++)
        {
            ui->listWidget_Teachers->item(j)->setHidden(true);
        }
    }
}

void TimetableItemsAdding::on_pushButton_ClearSubjects_clicked()
{
    ui->label_SubjectName->clear();
    ui->label_TeacherName->clear();
    subject = Subject();
    showSubjectsList();
    hideTeachers();
}

void TimetableItemsAdding::on_pushButton_ClearTeachers_clicked()
{
    ui->label_TeacherName->clear();
    teacher = Teacher();
    showTeachersList();
}

void TimetableItemsAdding::on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item)
{
    subject = CurrentUser::getInstance()->getSubjects()[ui->listWidget_Subjects->currentRow()];
    ui->label_SubjectName->setText(item->text());
    hideSubjects();
    showTeachersList();
}

void TimetableItemsAdding::on_listWidget_Teachers_itemDoubleClicked(QListWidgetItem *item)
{
    teacher = subject.getTeachers()[ui->listWidget_Teachers->currentRow()];
    ui->label_TeacherName->setText(item->text());
    hideTeachers();
}

void TimetableItemsAdding::on_radioButton_Numerator_clicked()
{
    repeating = NUMERATOR;
}

void TimetableItemsAdding::on_radioButton_FullWeek_clicked()
{
    repeating = NULLTYPE;
}

void TimetableItemsAdding::on_radioButton_Denominator_clicked()
{
    repeating = DENOMINATOR;
}

void TimetableItemsAdding::on_pushButton_Add_clicked()
{
    if(checkFields())
    {
        Plan plan(day, lesson, subject, ui->lineEdit_Room->text(), teacher, ui->lineEdit_Link->text(), repeating);

        if(ui->label_AddingPlan->text() == "Adding plan")
        {
            auto iterator = CurrentUser::getInstance()->getTimetable().find(std::make_pair(lesson, day));
            if(iterator != CurrentUser::getInstance()->getTimetable().end())
            {
                if(iterator->second.getRepeating() == repeating || iterator->second.getRepeating() == NULLTYPE)
                {
                    ui->label_AlreadyTaken->show();
                    return;
                }
                else
                {
                    iterator++;
                    if(iterator->second.getDay() == day && iterator->second.getLesson())
                    {
                        ui->label_AlreadyTaken->show();
                        return;
                    }
                }
            }
        }
        emit Save(plan);
        this->close();
    }
}
