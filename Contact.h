#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>

class Contact
{
public:
    Contact(std::string, std::string, std::string);
    void save();
    void deleteContact(long);
    void setName(std::string);
    void setPhone(std::string);
    void setEmail(std::string);
    std::string getName();
    std::string getPhone();
    std::string getEmail();
    std::string description();
    ~Contact();

private:
    static std::string storage;

    std::string name;
    std::string phone;
    std::string email;
};

#endif // CONTACT_H