#include <iostream>
using namespace std;

template<typename T>
class Node{
    public:
        T value;
        Node* next;
        Node() : value(), next(nullptr) {}
        Node(T x)  : value(x), next(nullptr) {}
        Node(T x, Node* next_node) : value(x), next(next_node) {}
};


template<typename T>
class List{
    private:
        Node<T>* head;
    public:
        List() : head(nullptr) {}
        void push_back(T x){
            Node<T>* new_node = new Node<T>(x,nullptr);  // Use initializer list to create new_node
            if(head == nullptr) head = new_node;
            else{
                Node<T>* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = new_node;
            }
        }
        void push_front(T x){
            Node<T>* new_node = new Node<T>(x,head);
            head = new_node;
        }
        T pop_front(){
            Node<T>* temp = head;
            T res = temp->value;
            head = head->next;
            delete temp;
            return res;
        }
        T pop_back(){
            if(head == NULL){cout<<"cannot pop an empty list."<<endl;exit(EXIT_FAILURE);}
            if(head->next == nullptr){
                T res = head->value;
                delete head;
                head = nullptr;
                return res;
            }
            Node<T>* before_last = head;
            Node<T>* last = head;
            while(before_last->next->next != nullptr){
                before_last = before_last->next;
            }
            last = before_last->next;
            T res = last->value;
            before_last->next = nullptr;
            delete last;
            return res;
        }
        void print(){
            if(head == nullptr) cout<<"[]";
            else{
                cout<<'[';
                Node<T>* temp = head;
                while(temp != nullptr){
                    cout<<temp->value<<", ";
                    temp = temp->next;
                }
                cout<<"\b\b]"<<endl;
            }
            return;
        }
        T at(int k){
            if(head == nullptr){
                cout<<"There are no elements.";
                exit(EXIT_FAILURE);
            }
            Node<T>* temp = head;
            for(int i=0;i<k;i++) temp = temp->next;
            return temp->value;
        }
        void pop_at(int k){
            if(head == nullptr){
                return;
            }
            if (k == 0){
                Node<T>* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node<T>* before = head;
            for(int i=0;i<k-1;i++) before = before->next;
            Node<T>* at = before->next;
            before->next = at->next;
            delete at;
        }
        int size(){
            int count = 0;
            Node<T>* temp = head;
            while(temp!=nullptr){
                temp = temp->next;
                count++;
            }
            return count;
        }
};

int main(){
    List<int> list;
    list.push_back(1);list.push_back(2);list.push_back(3);list.push_back(4);
    list.print();
    list.pop_front();
    list.print();
    list.pop_at(2);
    list.print();
    cout<<list.size();
    return 0;
}