#ifndef STUDENT_MAINWINDOW_H
#define STUDENT_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Student_MainWindow;
}

class Student_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Student_MainWindow(QWidget *parent = nullptr);
    ~Student_MainWindow();
    void setusername(QString a);//学生端设置用户名
    void closeEvent(QCloseEvent *event);//关闭事件

signals:
    void StuMainClosed();

private:
    Ui::Student_MainWindow *ui;
    QString username;//用户名
};

#endif // STUDENT_MAINWINDOW_H
