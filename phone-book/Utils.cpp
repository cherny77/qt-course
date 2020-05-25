#include "Utils.h"
    QRegExp phoneRe( "^[0-9\\-\\+]{9,15}$" );

bool isValidPhoneNumber(QString phoneNumber){
  return phoneRe.exactMatch( phoneNumber );
}
