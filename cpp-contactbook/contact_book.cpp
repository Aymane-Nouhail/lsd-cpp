#include<iostream>
#include <cstring>
#include <cmath>

# ifndef MAX_SIZE
# define MAX_SIZE 30
# endif

using namespace std;

class contact{
    public:
        char firstname[MAX_SIZE];
        char lastname[MAX_SIZE];
        char phonenumber[MAX_SIZE];
        int id;
};

class PhoneBook{
    public:
        contact contacts[8];
        int count_contacts = 0;
        void AddContact(char* name1,char * name2,char* phonenumber,int identifier){
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
        void truncate(int n){
            if(int(log10(n) + 1)>8){
                char buffer[MAX_SIZE];
                sprintf(buffer,"%d",n);
                truncate(buffer);
            }
            else cout<<n; 
        }
        void printContacts(){
            cout << "---------------------------------------------------"<<endl;
            cout << "first name|last name |phone nmbr|    id    " << endl;
            cout << "---------------------------------------------------"<<endl;
            for(int i=0;i<count_contacts && i<8;i++){
            truncate(contacts[i].firstname); cout<< "|" ;truncate(contacts[i].lastname); cout << "|";truncate(contacts[i].phonenumber); cout<< "|"; truncate(contacts[i].id);
            cout <<endl<<"---------------------------------------------------"<<endl;
            }
            //cout << contacts->firstname << "|"<<contacts->lastname<<"\t" <<contacts->phonenumber << "\t" <<contacts->id << endl;
        return;
        }
        void searchContacts(int id){
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
            truncate(contacts[res].firstname); cout<< "|" ;truncate(contacts[res].lastname); cout << "|";truncate(contacts[res].phonenumber); cout<< "|"; cout <<contacts[res].id;
            cout <<endl<<"---------------------------------------------------"<<endl;
            return;
        }
};

int main(){
    PhoneBook phonebook;
    char dashes[] = "-----------------------";
    cout << dashes <<"Hello, This is the interface for your Phone Book, please input one of the following numbers : "<<dashes<<endl;
    cout << "\t1. ADD : to add a new contact, you'll be prompted to enter the first and last names, the phone number and the id."<<endl;
    cout << "\t2. SEARCH : to search for a specific contact, please input his id."<<endl;
    cout << "\t3. EXIT : to exit the program"<<endl;
    cout << "\tyour choice is : ";
    int user_choice; scanf("%d",&user_choice); printf("\b");
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
        if(user_choice == 2){
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