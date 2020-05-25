#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QRegExp>
    const QString INVALID_NUMBER_MESS = "Number is invalid!";
    const QString EMPTY_NAME_MESS = "Name can`t be empty!";
    const QString EMPTY_SURNAME_MESS = "Surname can`t be empty!";
    const QString EMPTY_MESS = "Surname and name can`t be empty!";
    const QString EXIST_CONTACT_MESS = "Contact with these name and surname is already existed!";

    enum Modes
    {
        EDIT,
        SHOW,
        ADD
    };
bool isValidPhoneNumber(QString phoneNumber);
#endif // UTILS_H
