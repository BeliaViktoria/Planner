#include "agendaadding.h"
#include "ui_agendaadding.h"
#include "currentuser.h"

AgendaAdding::AgendaAdding() :
    QWidget(nullptr),
    ui(new Ui::AgendaAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    showSubjectsList();
    ui->pushButton_Deadline->setText(QDate::currentDate().toString("dd.MM.yyyy"));
}

AgendaAdding::AgendaAdding(Task task):
       QWidget(nullptr),
       ui(new Ui::AgendaAdding)
{
    ui->setupUi(this);
    hideErrorLabels();
    setValidation();
    ui->pushButton_Add->setText("Edit");
    ui->label_AddingTask->setText("Editing task");

    ui->lineEdit_Name->setText(task.getName());
    ui->label_SubjectName->setText(task.getSubject().getName());
    ui->pushButton_Deadline->setText(task.getDeadline().toString("dd.MM.yyyy"));
    showSubjectsList();
}

AgendaAdding::~AgendaAdding()
{
    delete ui;
}

bool AgendaAdding::checkFields()
{
    hideErrorLabels();
    bool status = true;
    if(ui->lineEdit_Name->text() == "")
    {
        ui->label_NessesaryField_1->show();
        status = false;
    }
    if(ui->label_SubjectName->text() == "")
    {
        ui->label_NessesaryField_2->show();
        status = false;
    }
    if(ui->pushButton_Deadline->text() == "")
    {
        ui->label_NessesaryField_3->show();
        status = false;
    }
    return status;
}

void AgendaAdding::hideErrorLabels()
{
    ui->label_NessesaryField_1->hide();
    ui->label_NessesaryField_2->hide();
    ui->label_NessesaryField_3->hide();
    ui->label_AlreadyExist->hide();
}

void AgendaAdding::setValidation()
{
    validatorName.setRegularExpression(QRegularExpression("[a-zA-Z0-9._%-+!#$&/=?^|~ ]+"));
    ui->lineEdit_Name->setValidator(&validatorName);
}

void AgendaAdding::showSubjectsList()
{
    ui->listWidget_Subjects->clear();
    for(Subject& item:CurrentUser::getInstance()->getSubjects())
    {
        ui->listWidget_Subjects->addItem(item.getName());
    }
    hideSubjects();
}

void AgendaAdding::hideSubjects()
{
    if(ui->label_SubjectName->text() != "")
    {
        for(int j = 0; j < ui->listWidget_Subjects->count(); j++)
        {
            ui->listWidget_Subjects->item(j)->setHidden(true);
        }
    }
}

void AgendaAdding::on_pushButton_Deadline_clicked()
{
    emit OpenPickUpDate();
}

void AgendaAdding::on_pushButton_ClearSubjects_clicked()
{
    ui->label_SubjectName->clear();
    showSubjectsList();
}

void AgendaAdding::on_pushButton_Add_clicked()
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
        Task task(ui->lineEdit_Name->text(), subject,
                    QDate::fromString(ui->pushButton_Deadline->text(), "dd.MM.yyyy"));

        if(ui->label_AddingTask->text() == "Adding task")
        {
            for(Task item : CurrentUser::getInstance()->getAgenda())
            {
                if(item == task)
                {
                    ui->label_AlreadyExist->show();
                    return;
                }
            }
        }
        emit Save(task);
        this->close();
    }
}

void AgendaAdding::on_listWidget_Subjects_itemDoubleClicked(QListWidgetItem *item)
{
    ui->label_SubjectName->setText(item->text());
    hideSubjects();
}

void AgendaAdding::setDate(QString date)
{
     ui->pushButton_Deadline->setText(date);
}
