#include "contacts.h"
#include "iostream"

Contacts::Contacts()
{
    /* Test data segment */
    QVector<QString> phones;
    phones.push_back("+3800500630057");
    phones.push_back("+3805754564333");
    Contact a("Andrey", "Rybak", phones);
    Contact b("Kyrill", "Sheremet", phones);
    Contact c("Ivan", "Chornokozynskyi", phones);
    Contact d("Vadim", "Kuch", phones);
    QVector<Contact> *contacts = new QVector<Contact>();
    contacts->push_back(a);
    contacts->push_back(b);
    contacts->push_back(c);
    contacts->push_back(d);
    _contacts = contacts;
    /* Test data segment */
}

void Contacts::add(Contact contact){
    _contacts->push_back(contact);
}

void Contacts::add(const QString name,
                   const QString surname,
                   const QVector<QString> phoneNumbers){
    Contact contact(name,surname,phoneNumbers);
    _contacts->push_back(contact);
}

Contact* Contacts::findContactbyFullname(QString fullname) {
         for (int i = 0; i < _contacts->size(); i++)
        {
         if ( !QString::compare((*_contacts)[i].fullname(), fullname, Qt::CaseInsensitive)) {
             return &(*_contacts)[i];
         }
        }
    return nullptr;
};

QVector<Contact>* Contacts::filterContacts(QString request) {
    QVector<Contact> *filtered = new QVector<Contact>();
    for (int i = 0; i < _contacts->size(); i++)
   {
       Contact contact = (*_contacts)[i];
        if (contact.fullname().contains(request,Qt::CaseInsensitive)) {
            filtered->push_back((*_contacts)[i]);
            continue;
        }

        QVector<QString> phones = contact.phoneNumbers();
        for(int i = 0; i < phones.size(); i++){
            if (phones[i].contains(request)) {
                filtered->push_back(contact);
                break;}
        }
    }
    return filtered;
};

bool Contacts::contains(QString fullname) {
    return findContactbyFullname(fullname) != nullptr;
};

void Contacts::remove(Contact contact){
_contacts->erase(std::remove(_contacts->begin(), _contacts->end(), contact), _contacts->end());
}

unsigned int Contacts::size(){
    return _contacts->size();
}
