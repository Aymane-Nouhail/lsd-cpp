#include "../include/contact_book.h"

using namespace std;

void PhoneBook::AddContact(char* name1,char * name2,char* phonenumber,int identifier){
    contacts[count_contacts%8].set_firstname(name1);
    contacts[count_contacts%8].set_lastame(name2);
    contacts[count_contacts%8].set_phonenumber(phonenumber);
    contacts[count_contacts%8].set_id(identifier);
    count_contacts++;
    return;
}

void PhoneBook::truncate(char* str){
    int n = strlen(str);
    char res[11];
    if(n>10){
        memcpy(res,str,9);
        res[9] = '.';
        res[10] = '\0';
    }
    else{
        memcpy(res,str,n);
        for(int i=n;i<10;i++) res[i] = ' ';
        res[10] = '\0';
    }
    cout << res;
    return;
}

void PhoneBook::truncate(int n){
    if(int(log10(n) + 1)>8){
        char buffer[MAX_SIZE];
        sprintf(buffer,"%d",n);
        truncate(buffer);
    }
    else cout<<n;
    return;
}

void PhoneBook::printContacts(){
    cout << CONST_DASHES<<endl;
    cout << "first name|last name |phone nmbr|identifier" << endl;
    cout << CONST_DASHES<<endl;
    for(int i=0;i<count_contacts && i<8;i++){
        truncate(contacts[i].get_firstname()); cout<< "|" ;
        truncate(contacts[i].get_lastname()); cout << "|";
        truncate(contacts[i].get_phonenumber()); cout<< "|";
        truncate(contacts[i].get_id());
        cout <<endl<<CONST_DASHES<<endl;
    }
    return;
}

void PhoneBook::searchContacts(int id){
    int res = -1;
    for(int i=0;i<count_contacts && i<8;i++){
        if(contacts[i].get_id() == id){
            res = i;
            break;
        }
    }
    if (res == -1){
        cout <<"THERE IS NO USER WITH THAT ID"<<endl;
        return;
    }
    cout << CONST_DASHES<<endl;
    cout << "first name|last name |phone nmbr|identifier" << endl;
    cout << CONST_DASHES<<endl;
    truncate(contacts[res].get_firstname()); cout<< "|" ;
    truncate(contacts[res].get_lastname()); cout << "|";
    truncate(contacts[res].get_phonenumber()); cout<< "|"; 
    cout <<contacts[res].get_id();
    cout <<endl<<CONST_DASHES<<endl;
    return;
}

