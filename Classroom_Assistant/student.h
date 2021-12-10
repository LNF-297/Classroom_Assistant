#ifndef STUDENT_H
#define STUDENT_H

#include <QWidget>

namespace Ui {
class Student;
}

class Student : public QWidget
{
    Q_OBJECT

public:
    explicit Student(QWidget *parent = nullptr);
    ~Student();
    void setattribute(int ui,QString pss,QString nam);

private:
    Ui::Student *ui;
    int Uid;
    QString Password,Name,Class;
};

#endif // STUDENT_H
