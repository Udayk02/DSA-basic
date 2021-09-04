#include<iostream>
// #include "postfix.cpp"
using namespace std;

class Stack{
    public:
    char a[100];
    int top = 0;
    void push(char b);
    char pop();
};

void Stack::push(char b){
    a[top] = b;
    top++;
}

char Stack::pop(){
    char n = a[top-1];
    top--;
    return n;
}

bool isOperand(int ch){
    if(ch>=65&&ch<=90){
        cout<<"*";
        return true;
    }
    return false;
}

int check(char ch){
    if(ch=='/'){
        return 4;
    }
    else if(ch=='*'){
        return 3;
    }
    else if(ch=='+'){
        return 2;
    }
    else if(ch=='('){
        return 1;
    }
    return 2;    
}

void conversion(char exp[]){
    Stack operatorStack;
    cout<<"Postfix expression: "; 
    for(int i=0;exp[i]!='\0';i++){
        if(isOperand(exp[i])){
            cout<<exp[i];
        }    
        else if(exp[i]=='('){
            operatorStack.push(exp[i]);
        }
        else if(exp[i]==')'){
            int n = operatorStack.top;
            while(operatorStack.a[n-1]!='('){
                char ch = operatorStack.pop();
                cout<<exp[i]; 
                n--;
            }
            operatorStack.pop();
        }
        else{
            int n = operatorStack.top;
            if(check(exp[i])>check(operatorStack.a[n-1])||(n==0)){
                operatorStack.push(exp[i]);
            }
            else{
                while((operatorStack.top>0)&&(check(exp[i]))<=check(operatorStack.a[n-1])){
                    char x = operatorStack.pop();
                    cout<<x;
                    n--;
                }
                operatorStack.push(exp[i]);
            }
        }
    }
    for(int i=0;operatorStack.top!=0;i++){
        char n = operatorStack.pop();
        cout<<n;
    }
}

int main(){
    char exp[10];
    cout<<"Enter the expression: ";
    for(int i=0;i<10;i++){
        cin>>exp[i];
    }
    conversion(exp);
    return 1;
}