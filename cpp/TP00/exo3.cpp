#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

using Stack = Node*;

//prototypes
void push(int x, Stack* stack);
int pop(Stack* stack);
void printStack(const Stack* stack);
Stack reverseStack(Stack);
Stack reverse_every_k(Stack,int);


void printStack(Stack stack) {
    if(stack == nullptr){ 
        cout<<"[ ]"<<endl;
        return;
    }
    cout<<'[';
    for (Stack current = stack; current != nullptr; current = current->next){

        if(current->next != nullptr) cout<< current->value << ", ";
        else cout<< current->value;
    }
    cout<<']'<<endl;
    return;
}
void push(int x, Stack* stack) {
    Node* new_node = new Node{ x, *stack }; 
    *stack = new_node;
}

int pop(Stack* stack) {
    if (*stack == nullptr) {
        exit(EXIT_FAILURE);
    }
    int res = (*stack)->value;
    auto temp = *stack;
    *stack = (*stack)->next;
    delete temp;
    return res;
}
void AjoutFinStack(Stack* stack, int x){
    Stack new_node = new Node{ x, nullptr };
    if (*stack == nullptr) {
        *stack = new_node;
        return;
    }
    Stack current = *stack;
    while(current->next != nullptr)
        current = current->next;
    current->next = new_node;
}

int checkInStack(Stack stack,int x){
    if (stack == nullptr) return 0;
    Stack current = stack;
    while(current != nullptr){
        if(current->value == x) return 1;
        current = current->next;
    }
    return 0;
}
Stack removeDuplicates(Stack stack){
    Stack current = stack;
    Stack unique = nullptr;
    while(current != nullptr){
        if(checkInStack(unique,current->value)  == 0)
            AjoutFinStack(&unique,current->value);
        current = current->next;
    }
    return unique;
}

int main(){
    cout<<"How many elements in the stack : ";
    int n; cin >> n;
    int input;
    cout<<"Enter the values : ";
    Stack stack = nullptr;
    for(int i=0;i<n;i++){
        cin >> input;
        AjoutFinStack(&stack,input);
    }
    cout<<"printing the stack : ";printStack(stack);
    Stack unique = removeDuplicates(stack);
    cout<<"the stack after removing duplicates : ";printStack(unique);
    return 0;
}