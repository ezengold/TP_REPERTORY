#include "Contact.h"

using namespace std;

Contact::Contact(string NAME, string PHONE, string EMAIL)
{
    this->name = NAME;
    this->phone = PHONE;
    this->email = EMAIL;
}

Contact::~Contact()
{
}
