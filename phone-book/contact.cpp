#include "contact.h"


Contact::Contact(const QString name,
                 const QString surname,
                 const QVector<QString> phoneNumbers):_name(name), _surname(surname), _phoneNumbers(phoneNumbers) {}

QString Contact::toString(){
   QString res = _name + " " + _surname + " ";
    for( int i = 0; i < _phoneNumbers.size(); i++) {
        res += _phoneNumbers[i];
        if(i != _phoneNumbers.size() - 1)
            res += " ";
    }
    return res;
}

bool Contact::operator==(const Contact& other) const {
    int x = QString::compare(this->fullname(), other.fullname());
    return x == 0;
};

QString Contact::fullname() const{
    return surname() + " " + name();
}
