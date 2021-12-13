#include "student.h"
#include "ui_student.h"
#include <qdebug.h>

Student::Student(const int &Sid,const QString &Password,const QString& Name,const QString &Class,QWidget *parent) :
    QWidget(parent),Sid(Sid),Password(Password),Name(Name),Class(Class),
    ui(new Ui::Student)
{
    ui->setupUi(this);
    resize(600,400);
    setWindowTitle("学生端首页");
    username = "";//由Sid获取username，如果username没用就不用管这个
    total_score = new Total_score(username);
    ui->SidLabel->setText(QString::number(Sid));
    ui->NameLabel->setText(Name);
    enterclass = new EnterClass();//进入课堂窗口
    connect(ui->GradesCheckButton, &QPushButton::clicked, total_score, &Total_score::show);
}

Student::~Student()
{
    delete ui;
    delete enterclass;
}

void Student::closeEvent(QCloseEvent *event){
    emit Logout();
    qDebug()<<"Logout信号已发出";
}

void Student::on_LogoutButton_clicked()
{
    this->close();
}


void Student::on_EnterClassButton_clicked()
{
    enterclass->show();
}
