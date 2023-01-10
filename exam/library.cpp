#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

int min(int a,int b){
    if(a<b) return a;
    else return b;
}
class Book{
    private:
        string name;
        string ISBN;
        string author;
        string link;
    public:
        Book(string my_name,string my_isbn,string my_author,string my_link) : name(my_name),ISBN(my_isbn),author(my_author),link(my_link) {}
        Book() {}
        string get_name(){return name;}
        string get_ISBN(){return ISBN;};
        string get_author(){return author;};
        string get_link(){return link;}
};
class Library{
    private:
      Book books[8];
      int count;
      void truncate(string a){
        int n = a.length();
        if(n<=10){
            cout<<right<<setw(10)<<a;
        }
        else{
            for(int i=0;i<9;i++) cout<<a[i];
            cout<<".";
        }
        return;
      }
    public:
        Library() : count(0) {}
        int get_count(){return count;}
        void create_book(string my_name,string my_isbn,string my_author,string my_link){
            books[count%8] = Book(my_name,my_isbn,my_author,my_link);
            count++;
        }
        void search_book(int index){
                cout<<"|name      |ISBN      |author    |link      |"<<endl;
                cout<<"---------------------------------------------"<<endl;
                cout<<"|";truncate(books[index].get_name());cout<<"|";truncate(books[index].get_ISBN());cout<<"|";
                truncate(books[index].get_author());cout<<"|";truncate(books[index].get_link());cout<<"|"<<endl;
        }
        void search_book(string my_name,string my_isbn,string my_author,string my_link){
            int index_res=-1;
            for(int i=0;i<min(count,count%8);i++){
                if(my_name == books[i].get_name() && my_isbn == books[i].get_ISBN() && my_author == books[i].get_author() && my_link == books[i].get_link())
                    index_res = i;
            }
            if(index_res == -1) cout<<"Found no books verifying those conditions."<<endl;
            else{
                cout<<"|name      |ISBN      |author    |link      |"<<endl;
                cout<<"---------------------------------------------"<<endl;
                cout<<"|";truncate(books[index_res].get_name());cout<<"|";truncate(books[index_res].get_ISBN());cout<<"|";
                truncate(books[index_res].get_author());cout<<"|";truncate(books[index_res].get_link());cout<<"|"<<endl;
            }
        }
        void show_books(){
            if(count == 0){cout<<"Empty library";return;}
            cout<<endl<<"|name      |ISBN      |author    |link      |"<<endl;
            cout<<"---------------------------------------------"<<endl;
            for(int i=0;i<min(count%8,8);i++){
                cout<<"|";truncate(books[i].get_name());cout<<"|";truncate(books[i].get_ISBN());cout<<"|";
                truncate(books[i].get_author());cout<<"|";truncate(books[i].get_link());cout<<"|"<<endl;
            }
        }
};



int main(){
    Library library;
    int user_choice;
    cout<<"Welcome to the library program. Please pick a number : "<<endl;
    cout<<"1.ADD \n2.SEARCH\n3.EXIT"<<endl;
    cout<<"pick your choice : ";
    cin>>user_choice;
    while(user_choice !=3){
        if(user_choice == 1){
            string my_name,my_isbn,my_author,my_link;
            cout<<"Enter name : ";cin>>my_name;
            cout<<"Enter ISBN : ";cin>>my_isbn;
            cout<<"Enter author : ";cin>>my_author;
            cout<<"Enter link : ";cin>>my_link;
            if (my_name.empty() || my_isbn.empty() || my_author.empty() || my_link.empty()) cout<<"There can be no empty line, please retry.";
            library.create_book(my_name,my_isbn,my_author,my_link);
            library.show_books();
        }
        if(user_choice == 2){
            int book_index;
            cout<<"Enter the index of the books to search using it : "; cin>>book_index;
            if(book_index > 8 || book_index>library.get_count()) cout<<"Invalid index, please retry."<<endl;
            library.search_book(book_index);
        }
        cout<<"Pick another number : ";
        cin>>user_choice;
    }
    /*
    library.create_book("name1","isbn1","author1","link1");
    library.create_book("name2","isbn1","author1","link1");
    library.create_book("name3","isbn1","author1","link1");
    library.create_book("name4","isbn1","author1","link1");
    library.create_book("name5","isbn1","author1","link1");
    library.create_book("name6","isbn1","author1","link1");
    library.create_book("name7","isbn1","author1","link1");
    library.create_book("name8","isbn1","author1","link1");
    library.create_book("name9","isbn1","author1","link1");
    //library.create_book("name9","isbn1","author1","link1");
    */
    return 0;
}