#include<iostream>
using namespace std;

class Stack{
    public:
    int a[100];
    int top = 0;
    void push(int num);
    int pop();
    void r_print();
};

void Stack::r_print(){
    cout<<"\nBinary Equivalent: ";
    for(int i=top-1;i>=0;i--){
        cout<<a[i];
    }
}

void Stack::push(int num){
    a[top] = num;
    top++;
}

int Stack::pop(){
    int n = a[top-1];
    top--;
    return n;
}

void binary(int n){
    Stack s;
    while(n!=0&&n!=1){
        int r = n%2;
        s.push(r);
        n = n/2;
    }
    s.push(n);
    s.r_print();
}

int main(){
    int n;
    cout<<"\nDecimal to Binary\n(please don't go for a bigger number)\n\nEnter a decimal number to get it's Binary equivalent: ";
    cin>>n;
    binary(n);
}