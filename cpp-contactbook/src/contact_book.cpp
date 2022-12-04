#include "../include/contact_book.h"

using namespace std;

void PhoneBook::AddContact(char* name1,char * name2,char* phonenumber,int identifier){
    //copying name1 into contacts[count_conacts].firstname
    int n = strlen(name1);
    memcpy(contacts[count_contacts%8].firstname,name1,n);
    contacts[count_contacts%8].firstname[n] = '\0';
    //copying name2 into contacts[count_conacts].lastname
    n = strlen(name2);
    memcpy(contacts[count_contacts].lastname,name2,n);
    contacts[count_contacts%8].lastname[n] = '\0';
    //likewise with phonenumber
    n = strlen(phonenumber);
    memcpy(contacts[count_contacts].phonenumber,phonenumber,n);
    contacts[count_contacts%8].phonenumber[n] = '\0';
    //finally with id
    contacts[count_contacts%8].id = identifier;
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
    cout << "---------------------------------------------------"<<endl;
    cout << "first name|last name |phone nmbr|    id    " << endl;
    cout << "---------------------------------------------------"<<endl;
    for(int i=0;i<count_contacts && i<8;i++){
        truncate(contacts[i].firstname); cout<< "|" ;truncate(contacts[i].lastname); cout << "|";truncate(contacts[i].phonenumber); cout<< "|"; truncate(contacts[i].id);
    cout <<endl<<"---------------------------------------------------"<<endl;
    }
    return;
}

void PhoneBook::searchContacts(int id){
    int res = -1;
    for(int i=0;i<count_contacts && i<8;i++){
        if(contacts[i].id == id){
            res = i;
            break;
        }
    }
    if (res == -1){
        cout <<"THERE IS NO USER WITH THAT ID"<<endl;
        return;
    }
    cout << "---------------------------------------------------"<<endl;
    cout << "first name|last name |phone nmbr|    id    " << endl;
    cout << "---------------------------------------------------"<<endl;
    truncate(contacts[res].firstname); cout<< "|" ;
    truncate(contacts[res].lastname); cout << "|";
    truncate(contacts[res].phonenumber); cout<< "|"; 
    cout <<contacts[res].id;
    cout <<endl<<"---------------------------------------------------"<<endl;
    return;
}

