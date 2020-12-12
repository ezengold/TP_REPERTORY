#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>
#include <fstream>
#include <vector>

class Contact
{
private:
    static std::string storage;
    static std::ifstream storage_reader;
    static std::ofstream storage_writer;

    std::string name;
    std::string phone;
    std::string email;

public:
    Contact();
    Contact(std::string, std::string, std::string);
    void setName(std::string);
    void setPhone(std::string);
    void setEmail(std::string);
    std::string getName();
    std::string getPhone();
    std::string getEmail();
    void remove();
    std::string description();
    static std::vector<Contact*> load();
    ~Contact();
};

#endif /* _CONTACT_H_ */