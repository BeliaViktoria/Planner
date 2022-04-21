#include "subjectadding.h"
#include "ui_subjectadding.h"
#include "currentuser.h"

#define MAX_TEACHERS_COUNT 3

SubjectAdding::SubjectAdding() :
    QWidget(nullptr),
    ui(new Ui::SubjectAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    showTeachersList();
}

SubjectAdding::SubjectAdding(Subject subject) :
    QWidget(nullptr),
    ui(new Ui::SubjectAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    ui->pushButton_Add->setText("Edit");
    ui->label_AddingSubject->setText("Editing subject");
    ui->lineEdit_Name->setText(subject.getName());
    QString teachersNames = subject.getTeachers()[0].getFullname() + "; ";
    if(subject.getTeachers()[1] != "")
    {
        teachersNames += subject.getTeachers()[1].getFullname() + "; ";
    }
    if(subject.getTeachers()[2] != "")
    {
        teachersNames += subject.getTeachers()[2].getFullname() + "; ";
    }
    ui->label_Teachers->setText(teachersNames);
    choosedColor = subject.getColor();
    setColor();
    showTeachersList();
}

SubjectAdding::~SubjectAdding()
{
    delete ui;
}

void SubjectAdding::setColor()
{
    ui->label_ColorName->setText(choosedColor.getColorName());
}

bool SubjectAdding::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_Name->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    if(ui->label_Teachers->text() == "")
    {
        ui->label_NessesaryField_2->show();
        status = false;
    }
    if(choosedColor == Color())
    {
        ui->label_NessesaryField_3->show();
        status = false;
    }
    return status;
}

void SubjectAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_NessesaryField_3->hide();
    ui->label_AlreadyExist->hide();
}

void SubjectAdding::setValidation()
{
    validatorName.setRegularExpression(QRegularExpression("[a-zA-Z ]+"));
    ui->lineEdit_Name->setValidator(&validatorName);
}

void SubjectAdding::showTeachersList()
{

    ui->listWidget_Teachers->clear();
    for(Teacher& item:CurrentUser::getInstance()->getTeachers())
    {
        ui->listWidget_Teachers->addItem(item.getFullname());
    }
    hideTeachers();
}

void SubjectAdding::hideTeachers()
{
    if(ui->label_Teachers->text() != "")
    {
        auto teachersNames = ui->label_Teachers->text().split("; ");
        if(teachersNames.length() > MAX_TEACHERS_COUNT)
        {
            for(int j = 0; j < ui->listWidget_Teachers->count(); j++)
            {
                    ui->listWidget_Teachers->item(j)->setHidden(true);
            }
            return;
        }

        for(int i = 0; i < teachersNames.length(); i++)
        {
            for(int j = 0; j < ui->listWidget_Teachers->count(); j++)
            {
                if(ui->listWidget_Teachers->item(j)->text() == teachersNames[i])
                {
                    ui->listWidget_Teachers->item(j)->setHidden(true);
                    break;
                }
            }
        }
    }
}

void SubjectAdding::on_pushButton_Add_clicked()
{
    if(checkFields())
    {
        Teacher teachers[3];
        auto teachersNames = ui->label_Teachers->text().split("; ");
        for(int i = 0; i < teachersNames.length(); i++)
        {
            for(Teacher item:CurrentUser::getInstance()->getTeachers())
            {
                if(item == teachersNames[i])
                {
                    teachers[i] = item;
                    break;
                }
            }
        }
        Subject subject(ui->lineEdit_Name->text(), teachers, choosedColor);

        if(ui->label_AddingSubject->text() == "Adding subject")
        {
            for(Subject& item : CurrentUser::getInstance()->getSubjects())
            {
                if (subject == item)
                {
                    ui->label_AlreadyExist->show();
                    return;
                }
            }
        }
        emit Save(subject);
        this->close();
    }
}

void SubjectAdding::on_pushButton_ClearTeachers_clicked()
{
    ui->label_Teachers->clear();
    showTeachersList();
}

void SubjectAdding::on_pushButton_Red_clicked()
{
    choosedColor = Color(QColor(255, 0, 0), "red");
    setColor();
}

void SubjectAdding::on_pushButton_Orange_clicked()
{
    choosedColor = Color(QColor(255, 170, 0), "orange");
    setColor();
}

void SubjectAdding::on_pushButton_Yellow_clicked()
{
    choosedColor = Color(QColor(255, 255, 0), "yellow");
    setColor();
}

void SubjectAdding::on_pushButton_LightGreen_clicked()
{
    choosedColor = Color(QColor(85, 255, 0), "light green");
    setColor();
}

void SubjectAdding::on_pushButton_Green_clicked()
{
    choosedColor = Color(QColor(0, 170, 0), "green");
    setColor();
}

void SubjectAdding::on_pushButton_LightBlue_clicked()
{
    choosedColor = Color(QColor(85, 170, 255), "light blue");
    setColor();
}

void SubjectAdding::on_pushButton_Blue_clicked()
{
    choosedColor = Color(QColor(85, 0, 255), "blue");
    setColor();
}

void SubjectAdding::on_pushButton_Purple_clicked()
{
    choosedColor = Color(QColor(170, 85, 255), "purple");
    setColor();
}

void SubjectAdding::on_pushButton_Pink_clicked()
{
    choosedColor = Color(QColor(255, 85, 255), "pink");
    setColor();
}

void SubjectAdding::on_pushButton_Brown_clicked()
{
    choosedColor = Color(QColor(203, 102, 0), "brown");
    setColor();
}

void SubjectAdding::on_pushButton_White_clicked()
{
    choosedColor = Color(QColor(255, 255, 255), "white");
    setColor();
}
void SubjectAdding::on_listWidget_Teachers_itemDoubleClicked(QListWidgetItem *item)
{
    ui->label_Teachers->setText(ui->label_Teachers->text() + item->text() + "; ");
    hideTeachers();
}

