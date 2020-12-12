#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

using namespace std;

string Contact::storage = "storage.txt";
ifstream Contact::storage_reader("storage.txt");
ofstream Contact::storage_writer("storage.txt", ios::app);

bool nameExists(string NAME);
bool phoneExists(string NAME);
bool emailExists(string NAME);
std::vector<std::string> split(const std::string &, const std::string &);

Contact::Contact()
{
}

Contact::Contact(string NAME, string PHONE, string EMAIL)
{
    if (!storage_writer)
    {
        storage_writer.open(storage, ios::app);
    }

    if (storage_writer)
    {
        if (!nameExists(NAME) && !phoneExists(PHONE))
        {
            this->name = NAME;
            this->phone = PHONE;
            this->email = EMAIL;

            storage_writer << this->name + "%" + this->phone + "%" + this->email;
        }
        else
        {
            cout << "\n Echec d'enregistrement ! Contact existant deja !\n";
        }
        storage_writer.close();
    }
    else
    {
        cout << "\n Echec d'enregistrement ! Memoire inacessible !\n";
    }
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

void Contact::remove()
{
}

string Contact::description()
{
    return this->name + "\t" + this->phone + "\t" + this->email;
}

vector<Contact *> Contact::load()
{
    vector<Contact *> contacts;

    string location = "storage.txt";
    storage_reader.open(location.c_str());

    if (storage_reader.fail())
    {
        cout << "\n Echec de lecture ! Memoire inacessible !\n";
        return contacts;
    }

    string line;
    while (getline(storage_reader, line))
    {
        cout << line << endl;
        // vector<string> data = split(line, "%");
        // contacts.push_back(new Contact(data[0], data[1], data[2]));
        storage_reader.close();
    }

    return contacts;
}

Contact::~Contact()
{
    storage_reader.close();
    storage_writer.close();
}

// FUNCTIONS
vector<string> split(const string &str, const string &delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos)
        {
            pos = str.length();
        }

        string token = str.substr(prev, pos - prev);

        if (!token.empty())
        {
            tokens.push_back(token);
        }
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

bool nameExists(string NAME)
{
    vector<Contact *> contacts = Contact::load();

    for (long i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getName().compare(NAME) == 0)
        {
            return true;
        }
    }
    return false;
}

bool phoneExists(string PHONE)
{
    vector<Contact *> contacts = Contact::load();

    for (long i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getPhone().compare(PHONE) == 0)
        {
            return true;
        }
    }
    return false;
}

bool emailExists(string EMAIL)
{
    vector<Contact *> contacts = Contact::load();

    for (long i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getEmail().compare(EMAIL) == 0)
        {
            return true;
        }
    }
    return false;
}