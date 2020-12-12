#include <iostream>
#include <vector>
#include <fstream>
#include "Contact.h"

using namespace std;

typedef long long unsigned int llui;

bool nameExists(string NAME);
bool phoneExists(string NAME);
bool emailExists(string NAME);
vector<string> split(const string &, const string &);

int main()
{
    bool play = true;
    while (play)
    {
        int choix;
        system("clear");
        cout << "\n";
        cout << "\n#######################################################";
        cout << "\n#                      REPERTOIRE                     #";
        cout << "\n#######################################################";
        cout << "\n#                                                     #";
        cout << "\n# 1- AJOUTER                                          #";
        cout << "\n#                                                     #";
        cout << "\n# 2- LISTE                                            #";
        cout << "\n#                                                     #";
        cout << "\n# 3- SUPPRIMER                                        #";
        cout << "\n#                                                     #";
        cout << "\n# 4- QUITTER                                          #";
        cout << "\n#                                                     #";
        cout << "\n#######################################################\n\n Choix : ";
        cin >> choix;

        if (choix == 1)
        {
            string NAME, PHONE, EMAIL;

            cout << "\n Nom : ";
            cin >> NAME;
            cout << "\n Numero : ";
            cin >> PHONE;
            cout << "\n Email : ";
            cin >> EMAIL;

            Contact contact(NAME, PHONE, EMAIL);
            contact.save();

            cout << "\n [+] : " + contact.description() << endl;

            string choice;
            cout << "\n";
            cout << "\n Entrez pour le menu principal (m), ou quitter (q) : ";
            cin >> choice;
            if (choice.compare("m") == 0 || choice.compare("M") == 0)
            {
                system("clear");
            }
            else if (choice.compare("q") == 0 || choice.compare("Q") == 0)
            {
                play = false;
                return EXIT_SUCCESS;
            }
            else
            {
                return EXIT_FAILURE;
            }
        }
        else if (choix == 2)
        {
            system("clear");
            cout << "\n";
            cout << "\n#######################################################";
            cout << "\n#                  LISTE DES CONTACTS                 #";
            cout << "\n#######################################################";

            vector<Contact *> contacts;

            ifstream storage_reader("storage/storage.txt");

            if (storage_reader.is_open())
            {
                string ligne;
                vector<string> data;
                while (getline(storage_reader, ligne))
                {
                    data = split(ligne, "%");
                    contacts.push_back(new Contact(data[0], data[1], data[2]));
                }

                storage_reader.close();
            }
            else
            {
                cout << "\n Echec de lecture ! Memoire inacessible !\n\n";

                string choice;
                cout << "\n";
                cout << "\n Entrez pour le menu principal (m), ou quitter (q) : ";
                cin >> choice;
                if (choice.compare("m") == 0 || choice.compare("M") == 0)
                {
                    system("clear");
                }
                else if (choice.compare("q") == 0 || choice.compare("Q") == 0)
                {
                    play = false;
                    return EXIT_SUCCESS;
                }
                else
                {
                    return EXIT_FAILURE;
                }
            }

            if (contacts.size() == 0)
            {
                cout << "\n#                                                     #";
                cout << "\n#               Aucun contact disponible              #";
                cout << "\n#                                                     #";
                cout << "\n#######################################################";
            }
            else
            {
                for (llui i = 0; i < contacts.size(); i++)
                {
                    cout << "\n  " << (i + 1) << "- " + contacts[i]->description() << endl;
                }

                cout << "\n#######################################################";
            }

            string choice;
            cout << "\n";
            cout << "\n Entrez pour le menu principal (m), ou quitter (q) : ";
            cin >> choice;
            if (choice.compare("m") == 0 || choice.compare("M") == 0)
            {
                system("clear");
            }
            else if (choice.compare("q") == 0 || choice.compare("Q") == 0)
            {
                play = false;
                return EXIT_SUCCESS;
            }
            else
            {
                return EXIT_FAILURE;
            }
        }
        else if (choix == 3)
        {
            system("clear");
            cout << "\n";
            cout << "\n#######################################################";
            cout << "\n#                  LISTE DES CONTACTS                 #";
            cout << "\n#######################################################";

            vector<Contact *> contacts;

            ifstream storage_reader("storage/storage.txt");

            if (storage_reader.is_open())
            {
                string ligne;
                vector<string> data;
                while (getline(storage_reader, ligne))
                {
                    data = split(ligne, "%");
                    contacts.push_back(new Contact(data[0], data[1], data[2]));
                }

                storage_reader.close();
            }
            else
            {
                cout << "\n Echec de lecture ! Memoire inacessible !\n\n";

                string choice;
                cout << "\n";
                cout << "\n Entrez pour le menu principal (m), ou quitter (q) : ";
                cin >> choice;
                if (choice.compare("m") == 0 || choice.compare("M") == 0)
                {
                    system("clear");
                }
                else if (choice.compare("q") == 0 || choice.compare("Q") == 0)
                {
                    play = false;
                    return EXIT_SUCCESS;
                }
                else
                {
                    return EXIT_FAILURE;
                }
            }

            if (contacts.size() == 0)
            {
                cout << "\n#                                                     #";
                cout << "\n#               Aucun contact disponible              #";
                cout << "\n#                                                     #";
                cout << "\n#######################################################";
            }
            else
            {
                for (llui i = 0; i < contacts.size(); i++)
                {
                    cout << "\n  " << (i + 1) << "- " + contacts[i]->description() << endl;
                }

                cout << "\n#######################################################";
            }

            long order;
            cout << "\n";
            cout << "\n Entrez le numero d'ordre du contact a supprimer : ";
            cin >> order;

            if ((llui)order <= contacts.size() && order > 0)
            {
                cout << "\n [-] : " + contacts[order - 1]->description() << endl
                     << "\n ";
                contacts[order - 1]->deleteContact(order);

                string choice;
                cout << "\n";
                cout << "\n Entrez pour le menu principal (m), ou quitter (q) : ";
                cin >> choice;
                if (choice.compare("m") == 0 || choice.compare("M") == 0)
                {
                    system("clear");
                }
                else if (choice.compare("q") == 0 || choice.compare("Q") == 0)
                {
                    play = false;
                    return EXIT_SUCCESS;
                }
                else
                {
                    return EXIT_FAILURE;
                }
            }
        }
        else if (choix == 4)
        {
            cout << "\n BYE !\n";
            play = false;
        }
    }

    return EXIT_SUCCESS;
}

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

bool nameExists(string NAME, vector<Contact *> contacts)
{
    for (llui i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getName().compare(NAME) == 0)
        {
            return true;
        }
    }
    return false;
}

bool phoneExists(string PHONE, vector<Contact *> contacts)
{
    for (llui i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getPhone().compare(PHONE) == 0)
        {
            return true;
        }
    }
    return false;
}

bool emailExists(string EMAIL, vector<Contact *> contacts)
{
    for (llui i = 0; i < contacts.size(); i++)
    {
        Contact *contact = contacts[i];

        if (contact->getEmail().compare(EMAIL) == 0)
        {
            return true;
        }
    }
    return false;
}