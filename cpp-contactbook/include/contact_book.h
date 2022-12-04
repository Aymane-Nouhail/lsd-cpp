#include<iostream>
#include <cstring>
#include <cmath>

# ifndef MAX_SIZE
# define MAX_SIZE 30
# endif

# define CONST_DASHES "---------------------------------------------------"

class contact{
    public:
        void set_firstname(char* name){
            int n = strlen(name);
            memcpy(firstname,name,n);
            firstname[n] = '\0';
            return;
        }
        char* get_firstname(){return firstname;}
        void set_lastame(char* name){
            int n = strlen(name);
            memcpy(lastname,name,n);
            lastname[n] = '\0';
            return;
        }
        char* get_lastname(){return lastname;}
        void set_phonenumber(char* name){
            int n = strlen(name);
            memcpy(phonenumber,name,n);
            phonenumber[n] = '\0';
            return;
        }
        char* get_phonenumber(){return phonenumber;}
        void set_id(int n){
            id = n;
            return;
        }
        int get_id(){return id;}
    private:
        char firstname[MAX_SIZE];
        char lastname[MAX_SIZE];
        char phonenumber[MAX_SIZE];
        int id;
};

class PhoneBook{
    public:
        void AddContact(char* /*firstname*/,char */*lastname*/,char* /*phonenumber*/ ,int /*id*/);
        void printContacts();
        void searchContacts(int /*id*/);
    private:
        contact contacts[8];
        int count_contacts = 0;
        void truncate(char*);
        void truncate(int);
};