#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <QtDebug>
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include <db_management.h>
//#include <db_operator.h>

/*
namespace action_type
{
    const QString command_login="login",
                  command_logout="logout",
                  command_register="register";
}
//*/

class serverconnection : public QObject
{
    Q_OBJECT
public:
    explicit serverconnection(QThread* thread,qintptr sock,QObject *parent = nullptr);
    ~serverconnection();
    void login(const QJsonObject &obj);
    void reg(const QJsonObject &obj);
    void attend(const QJsonObject &obj);
    void newclass(const QJsonObject &obj);
public slots:
    void quit();
    void action();
signals:
    void distroy(serverconnection* connection,QThread* thread);
    void stop(serverconnection* connection);
private:
    QTcpSocket* tcp;
    QThread *thread;
    QDateTime time;
    QString ip;
    QString username;
    QString type;
    DB_Management *db;
};

#endif // SERVERCONNECTION_H