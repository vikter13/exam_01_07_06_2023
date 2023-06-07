#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QString>
#include <QStringList>
#include <QDebug>


QString parsing(QString inputString);

QString start(QString log, QString roomname);
QString break_room(QString log);
QString stats(QString log_f);
QString rooms(QString log_f);
QString newroom(QString log_f);

#endif // FUNCTIONS_H
