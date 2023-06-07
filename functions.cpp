#include "functions.h"
#include "database.h"

QString parsing(QString inputString){
    /* InputString = "NameOfFunc&Arg1&arg2"
       хотим возвратить NameOfFunc (Arg1, arg2);
    */

    qDebug() << inputString;
    QStringList inputString_list = inputString.split('&');
    qDebug() << inputString_list;
    QString NameOfFunc = inputString_list.front();
    inputString_list.pop_front(); //удаляет имя функции из списка NameOfFunc


    if (NameOfFunc == "start")
        return start(inputString_list.at(0), inputString_list.at(1));
    if (NameOfFunc == "break_room")
        return break_room(inputString_list.at(0));
    if (NameOfFunc == "stats")
        return stats(inputString_list.at(0));
    if (NameOfFunc == "rooms")
        return rooms(inputString_list.at(0));
    if (NameOfFunc == "newroom")
        return newroom(inputString_list.at(0));


    return 0;
}


QString start(QString log, QString roomname){
    QString querry7 =
            QString("SELECT COUNT(*) FROM data;");
    QString result7 = DataBase::getInstance()->sendQuerry(querry7);
    if (result7 == "7 "){
        newroom("log_f");

        QString querry =
                QString("INSERT INTO data (login, roomname) VALUES ('%1', '%2');").arg(log).arg(roomname);

        QString result = DataBase::getInstance()->sendQuerry(querry);
        qDebug() << result;
        if (result.isEmpty())
            return "пользователь в ожидании";
        else
            return "пользователь уже есть";
        }
    else {
    QString querry =
            QString("INSERT INTO data (login, roomname) VALUES ('%1', '%2');").arg(log).arg(roomname);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    if (result.isEmpty())
        return "пользователь добавлен в очередь";
    else
        return "пользователь уже есть в очереди";
    }
}

QString break_room(QString log){
    QString querry =
            QString("DELETE FROM data WHERE login = '%1';").arg(log);

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
}

QString stats(QString log_f){
    QString querry =
            QString("SELECT login FROM data;");

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
    return result;
}

QString rooms(QString log_f){
    QString querry =
            QString("SELECT login FROM data;");

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
}

QString newroom(QString log_f){
    QString querry =
            QString("DELETE FROM data;");

    QString result = DataBase::getInstance()->sendQuerry(querry);
    qDebug() << result;
}

