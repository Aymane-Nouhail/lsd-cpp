#include<iostream>
#include <cstring>

using namespace std;

class contact{
    public:
        char firstname[20];
        char lastname[20];
        char phonenumber[20];
        int id;
};

class PhoneBook{
    public:
        contact contacts[8];
        int count_contacts=0;
        void AddContact(char* name1,char * name2,char* phonenumber,int identifier){
            label:
            if(count_contacts<=8){
                //copying name1 into contacts[count_conacts].firstname
                int n = strlen(name1);
                memcpy(contacts[count_contacts].firstname,name1,n);
                contacts[count_contacts].firstname[n] = '\0';
                //copying name2 into contacts[count_conacts].lastname
                n = strlen(name2);
                memcpy(contacts[count_contacts].lastname,name2,n);
                contacts[count_contacts].lastname[n] = '\0';
                //likewise with phonenumber
                n = strlen(phonenumber);
                memcpy(contacts[count_contacts].phonenumber,phonenumber,n);
                contacts[count_contacts].phonenumber[n] = '\0';
                //finally with id
                contacts[count_contacts].id = identifier;
                count_contacts++;
            }
            else{
                count_contacts = 0;
                goto label;
            }
            return;
        }
        void truncate(char* str){
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
        void printContacts(){
            cout << "==================================================="<<endl;
            cout << "first name|last name |phone nmbr|    id    " << endl;
            cout << "==================================================="<<endl;
            for(int i=0;i<count_contacts;i++){
            truncate(contacts[i].firstname); cout<< "|" ;truncate(contacts[i].lastname); cout << "|";truncate(contacts[i].phonenumber); cout<< "|"; cout <<contacts[i].id;
            cout <<endl<<"---------------------------------------------------"<<endl;
            }
            //cout << contacts->firstname << "|"<<contacts->lastname<<"\t" <<contacts->phonenumber << "\t" <<contacts->id << endl;
        return;
        }
        void searchContacts(int id){
            int res = -1;
            for(int i=0;i<count_contacts;i++){
                if(contacts[i].id == id){
                    res = i;
                    break;
                }
            }
            if (res == -1){
                cout <<"THERE IS NO USER WITH THAT ID"<<endl;
                return;
            }
            cout << "==================================================="<<endl;
            cout << "first name|last name |phone nmbr|    id    " << endl;
            cout << "==================================================="<<endl;
            truncate(contacts[res].firstname); cout<< "|" ;truncate(contacts[res].lastname); cout << "|";truncate(contacts[res].phonenumber); cout<< "|"; cout <<contacts[res].id;
            cout <<endl<<"---------------------------------------------------"<<endl;
            return;
        }
};

int main(){
    PhoneBook phonebook;
    cout << "Hello, This is the interface for your Phone Book, please input one of the following numbers : "<<endl;
    cout << "1. ADD : to add a new contact, you'll be prompted to enter the first and last names, the phone number and the id."<<endl;
    cout << "2. SEARCH : to search for a specific contact, please input his id."<<endl;
    cout << "3. EXIT : to exit the program"<<endl;
    int user_choice; cin >> user_choice;
    while(user_choice != 3){
        if (user_choice == 1){
            char firstname[20]; 
            char lastname[20];
            char phonenumber[11];
            int id;
            cout <<"enter the first name : ";
            cin >> firstname;
            cout<<endl<<"enter the last name : ";
            cin >> lastname;
            cout<<endl<<"enter the phone number : ";
            cin >> phonenumber;
            cout<<endl<<"enter the id :";
            cin >> id;
            phonebook.AddContact(firstname,lastname,phonenumber,id);
            phonebook.printContacts();
        }
        if(user_choice == 2){
            int id_choice;
            cout << "Enter the id of the person : ";
            cin >> id_choice;
            phonebook.searchContacts(id_choice);
        }
        cout << "Enter another number : ";
        cin >> user_choice;
    }
    /*
    char firstname1[] = "Aymane";
    char lastname1[] = "Nouhail";
    char phonenumber1[] = "0777741021";
    phonebook.AddContact(firstname1,lastname1,phonenumber1,1);
    char firstname2[] = "Patrick";
    char lastname2[] = "Bateman";
    char phonenumber2[] = "0726891829";
    phonebook.AddContact(firstname2,lastname2,phonenumber2,2);
    phonebook.printContacts();
    */
    cout << "=====PROGRAM EXITED SUCCESSFULLY=====";
    return 0;
}