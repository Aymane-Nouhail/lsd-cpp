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

Stack reverseStack(Stack stack) {
    Stack reversed = nullptr;
    for (Stack current = stack; current != nullptr; current = current->next) {
        push(current->value, &reversed);
    }
    return reversed;
}

void AjoutFinStack(Stack* stack, int x){
    Node* new_node = new Node{ x, nullptr };
    if (*stack == nullptr) {
        *stack = new_node;
        return;
    }
    Node* current = *stack;
    while(current->next != nullptr)
        current = current->next;
    current->next = new_node;
}

void appendStack(Stack* start, Stack* end) {
    for (Stack current = *end; current != nullptr; current = current->next) {
        AjoutFinStack(start,current->value);
    }
}

Stack reverse_every_k(Stack stack, int k){
    Stack reversed = nullptr;
    Stack current = stack;
    while (current != nullptr) {
        Stack group = nullptr;
        for (int i = 0; i < k; i++) {
            if (current == nullptr) break;
            int val = current->value;
            push(val, &group);
            current = current->next;
        }
        //printStack(group);
        appendStack(&reversed,&group);
    }
    return reversed;
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
    int k; cout<<"Enter the value of k : " ; cin >> k;
    cout<<"printing the stack : ";printStack(stack);
    Stack reversed = reverse_every_k(stack,k);
    cout<<"the stack after being reversed every "<<k<<" elements : ";printStack(reversed);
    return 0;
}