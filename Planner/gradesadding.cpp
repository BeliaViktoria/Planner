#include "gradesadding.h"
#include "ui_gradesadding.h"
#include "currentuser.h"

GradesAdding::GradesAdding() :
    QWidget(nullptr),
    ui(new Ui::GradesAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    showSubjectsList();
    ui->pushButton_Date->setText(QDate::currentDate().toString("dd.MM.yyyy"));
}

GradesAdding::GradesAdding(Grade grade) :
    QWidget(nullptr),
    ui(new Ui::GradesAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    ui->pushButton_Add->setText("Edit");
    ui->label_AddingGrade->setText("Editing subject");

    ui->lineEdit_YourGrade->setText(QString::number(grade.getCurrentGrade()));
    ui->lineEdit_MaxGrade->setText(QString::number(grade.getMaxGrade()));
    ui->label_SubjectName->setText(grade.getSubject().getName());
    ui->pushButton_Date->setText(grade.getDate().toString("dd.MM.yyyy"));
    ui->textEdit_Note->setText(grade.getNote());
    showSubjectsList();
}

GradesAdding::~GradesAdding()
{
    delete ui;
}

bool GradesAdding::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_YourGrade->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    if(ui->lineEdit_MaxGrade->text() == "")
    {
        ui->label_NessesaryField_2->show();
        status = false;
    }
    if(ui->label_SubjectName->text() == "")
    {
        ui->label_NessesaryField_3->show();
        status = false;
    }
    return status;
}

void GradesAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_NessesaryField_3->hide();
}

void GradesAdding::setValidation()
{
    validatorGrade.setRegularExpression(QRegularExpression("[0-9]+"));
    ui->lineEdit_YourGrade->setValidator(&validatorGrade);
    ui->lineEdit_MaxGrade->setValidator(&validatorGrade);
}

void GradesAdding::showSubjectsList()
{
    ui->listWidget_Subjects->clear();
    for(Subject& item:CurrentUser::getInstance()->getSubjects())
    {
        ui->listWidget_Subjects->addItem(item.getName());
    }
    hideSubjects();
}

void GradesAdding::hideSubjects()
{
    if(ui->label_SubjectName->text() != "")
    {
        for(int j = 0; j < ui->listWidget_Subjects->count(); j++)
        {
            ui->listWidget_Subjects->item(j)->setHidden(true);
        }
    }
}

void GradesAdding::on_pushButton_Date_clicked()
{
    emit OpenPickUpDate();
}

void GradesAdding::on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item)
{
    ui->label_SubjectName->setText(item->text());
    hideSubjects();
}

void GradesAdding::on_pushButton_Add_clicked()
{
    if(checkFields())
    {
        Subject subject;
        for(Subject item : CurrentUser::getInstance()->getSubjects())
        {
            if(item.getName() == ui->label_SubjectName->text())
            {
                subject = item;
                break;
            }
        }
        Grade grade(ui->lineEdit_YourGrade->text().toInt(), ui->lineEdit_MaxGrade->text().toInt(),
                    subject, QDate::fromString(ui->pushButton_Date->text(), "dd.MM.yyyy"), ui->textEdit_Note->toPlainText());

        emit Save(grade);
        this->close();
    }
}

void GradesAdding::on_pushButton_ClearSubjects_clicked()
{
    ui->label_SubjectName->clear();
    showSubjectsList();
}

void GradesAdding::setDate(QString date)
{
    ui->pushButton_Date->setText(date);
}
