#include<iostream>
#include <cstring>
#include <cmath>

# ifndef MAX_SIZE
# define MAX_SIZE 30
# endif

class contact{
    public:
        char firstname[MAX_SIZE];
        char lastname[MAX_SIZE];
        char phonenumber[MAX_SIZE];
        int id;
};

class PhoneBook{
    public:
        void AddContact(char*,char *,char*,int);
        void printContacts();
        void searchContacts(int);
    private:
        contact contacts[8];
        int count_contacts = 0;
        void truncate(char*);
        void truncate(int);
};