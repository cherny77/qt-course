#ifndef CONTACTSSINGLETON_H
#define CONTACTSSINGLETON_H
#include "contacts.h"

class ContactsSingleton
{
public:
    static Contacts * getInstance() {
           if(!_instance){

               _instance = new Contacts();

           }
           return _instance;
       }
private:
    static Contacts * _instance;
       ContactsSingleton() {}
       ContactsSingleton( const ContactsSingleton& );
       ContactsSingleton& operator=( ContactsSingleton& );
};

#endif // CONTACTSSINGLETON_H
