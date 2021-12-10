#ifndef TEACHER_MAINWINDOW_H
#define TEACHER_MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class Teacher_MainWindow;
}

class Teacher_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teacher_MainWindow(QWidget *parent = nullptr);
    ~Teacher_MainWindow();
    void setusername(QString a);
    void closeEvent(QCloseEvent *event);//关闭事件

signals:
    void TeaLogout();//注销信号

private:
    Ui::Teacher_MainWindow *ui;
    QString username;//用户名
};

#endif // TEACHER_MAINWINDOW_H
