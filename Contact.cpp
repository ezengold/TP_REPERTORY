#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Contact.h"

typedef long long unsigned int llui;

using namespace std;

string Contact::storage = "storage/storage.txt";
void removeLine(long, string);

Contact::Contact(string NAME, string PHONE, string EMAIL)
{
    this->name = NAME;
    this->phone = PHONE;
    this->email = EMAIL;
}

void Contact::save()
{
    ofstream storage_writer(storage, ios::app);

    if (storage_writer.is_open())
    {
        string ligne = this->name + "%" + this->phone + "%" + this->email;
        storage_writer << ligne << endl;
        storage_writer.close();
    }
    else
    {
        cout << "\n Echec d'enregistrement ! Memoire inacessible !\n\n ";
        system("pause");
    }
}

void Contact::deleteContact(long ORDER)
{
    removeLine(ORDER, storage);
    this->~Contact();
}

void Contact::setName(string NAME)
{
    this->name = NAME;
}

void Contact::setPhone(string PHONE)
{
    this->phone = PHONE;
}

void Contact::setEmail(string EMAIL)
{
    this->email = EMAIL;
}

string Contact::getName()
{
    return this->name;
}

string Contact::getPhone()
{
    return this->phone;
}

string Contact::getEmail()
{
    return this->email;
}

string Contact::description()
{
    return this->name + "\t" + this->phone + "\t" + this->email;
}

Contact::~Contact()
{
}

void removeLine(long order, string path)
{

    string line;
    ifstream fin;

    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    ofstream temp;
    temp.open("temp.txt");
    long position(0);

    while (getline(fin, line))
    {
        position++;
        // write all lines to temp other than the line marked for erasing
        if (position != order)
            temp << line << endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char *p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}