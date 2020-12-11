#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>
#include <fstream>

class Contact
{
private:
    static std::ifstream storage_reader;
    static std::ofstream storage_writer;
    std::string name;
    std::string phone;
    std::string email;

public:
    Contact(std::string, std::string, std::string);
    ~Contact();
};

#endif /* _CONTACT_H_ */