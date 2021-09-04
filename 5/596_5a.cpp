#include<iostream>
using namespace std;

class Stack{
    int max;
    int a[100];
    int top = 0;
    public:
    Stack();
    void push();
    void pop();
    void peek();
    void print();
};

Stack::Stack(){
    cout<<"\nEnter the Stack Size: ";
    cin>>max;
}

void Stack::push(){
    if(top==max){
        cout<<"\nStack overflow !\n";
    }
    else{
        int n;
        cout<<"\nEnter value: ";
        cin>>n;
        a[top] = n;
        top++;
        cout<<"Value added";
    }
}

void Stack::pop(){
    if(top==0){
        cout<<"\nStack underflow !\n";
    }
    else{
        cout<<"The popped element is "<<a[top-1]<<endl;
        top--;
    }
}

void Stack::peek(){
    if(top==0){
        cout<<"\nStack underflow\n";
    }
    else{
        cout<<"\nThe top element of the stack is: "<<a[top-1];
    }
}

void Stack::print(){
    if(top==0){
        cout<<"\nNo elements to print.\n";
        return;
    }
    cout<<"\nThe elements in the stack are: ";
    for(int i=0;i<top;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    Stack s;
    cout<<"\nStack Implementation\n";
    int option;
    do{
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit";
        cout<<"\n\nChoose any option: ";
        cin>>option;
        switch(option){
            case 1:
                s.push();
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                s.print();
                break;
            case 5:
                cout<<"\nExiting\n\n";
                break;
            default:
                cout<<"\nInvalid option.\n";
                break;
        }
    }while(option!=5);
    return 1;
}