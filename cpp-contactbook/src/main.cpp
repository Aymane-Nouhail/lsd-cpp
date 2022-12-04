#include "../include/contact_book.h"

using namespace std;

//to compile, cd into contact_book then run : g++ -o contact_book.exe ./src/*

int main(){
    PhoneBook phonebook;
    cout << "~~~~~~~~~~~~~~~~Hello, This is the interface for your Phone Book, please input one of the following numbers : ~~~~~~~~~~~~~~~~"<<endl;
    cout << "\t1. ADD : to add a new contact, you'll be prompted to enter the first and last names, the phone number and the id."<<endl;
    cout << "\t2. SEARCH : to search for a specific contact, please input his id."<<endl;
    cout << "\t3. EXIT : to exit the program"<<endl;
    cout << "\tyour choice is : ";
    int user_choice; scanf("%d",&user_choice);
    while(user_choice != 3){
        if (user_choice == 1){
            char firstname[MAX_SIZE]; 
            char lastname[MAX_SIZE];
            char phonenumber[MAX_SIZE];
            int id;
            cout <<"\tenter the first name : ";
            fseek(stdin,0,SEEK_END); //clearing stdin
            cin.getline(firstname,MAX_SIZE-1);
            cout<<endl<<"\tenter the last name : ";
            fseek(stdin,0,SEEK_END); //clearing stdin
            cin.getline(lastname,MAX_SIZE-1);
            cout<<endl<<"\tenter the phone number : ";
            cin >> phonenumber;
            cout<<endl<<"\tenter the id : ";
            cin >> id;
            phonebook.AddContact(firstname,lastname,phonenumber,id);
            phonebook.printContacts();
        }
        else if(user_choice == 2){
            int id_choice;
            cout << "\tEnter the id of the person : ";
            cin >> id_choice;
            phonebook.searchContacts(id_choice);
        }
        cout << "\tEnter another number : ";
        cin >> user_choice;

    }
    cout << "==============PROGRAM TERMINATED SUCCESSFULLY==============";
    return 0;
}