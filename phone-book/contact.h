#ifndef CONTACT_H
#define CONTACT_H
#include "QString"
#include "QVector"

class Contact
{
public:
    Contact();
    Contact(const QString, const QString, const QVector<QString>);

    QString surname() const {return _surname;}
    QString& surname() {return _surname;}

    QString name() const {return _name;}
    QString& name() {return _name;}

    QVector<QString> phoneNumbers() const {return _phoneNumbers;}
    QVector<QString>& phoneNumbers() {return _phoneNumbers;}


    QString toString();
    QString fullname() const ;

    bool operator==(const Contact& other) const;

private:
    QString  _name;
    QString  _surname;
    QVector<QString> _phoneNumbers;
};

#endif // CONTACT_H
