#ifndef CONTACTS_H
#define CONTACTS_H
#include "QVector"
#include "contact.h"
#include "iostream"


class Contacts
{
public:
    Contacts();
    void add(Contact contact);
    void add(const QString name,
             const QString surname,
             const QVector<QString> phoneNumbers);
    void remove(Contact contact);
    unsigned int size();
    QVector<Contact> contacts() const {
        return *_contacts;}
    QVector<Contact>& contacts() {

        return *_contacts;}

    Contact* findContactbyFullname(QString);

    bool contains(QString);

    QVector<Contact>* filterContacts(QString);

private:
    QVector<Contact> *_contacts;
};

#endif // CONTACTS_H
