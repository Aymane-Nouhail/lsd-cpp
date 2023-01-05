#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* next;
};

using Stack = Node*;

void push(int x, Stack* stack);
int pop(Stack* stack);
void printStack(const Stack* stack);

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

int main(){
    cout<<"How many elements in the stack : ";
    int n; cin >> n;
    int input;
    cout<<"Enter the values : ";
    Stack stack = nullptr;
    for(int i=0;i<n;i++){
        cin >> input;
        push(input, &stack);
    }
    cout<<"printing the stack : ";printStack(stack);
    cout<<"Popping the stack : "<<pop(&stack)<<endl;
    cout<<"the stack after being popped :"; printStack(stack);
    return 0;
}