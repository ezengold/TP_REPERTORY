#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

#include "Contact.h"

using namespace std;

int system(const char *_command);

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

            vector<Contact *> conts = Contact::load();

            if (conts.size() == 0)
            {
                cout << "\n#                                                     #";
                cout << "\n#               Aucun contact disponible              #";
                cout << "\n#                                                     #";
                cout << "\n#######################################################";
            }
            else
            {

                for (long i = 0; i < conts.size(); i++)
                {
                    Contact *contact = conts[i];
                    cout << "  " + contact->description() << endl;
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
            cout << "3\n";
        }
        else if (choix == 4)
        {
            cout << "\n BYE !\n";
            play = false;
        }
    }

    return EXIT_SUCCESS;
}