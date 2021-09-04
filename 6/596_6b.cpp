#include<iostream>
using namespace std;

class Stack{
    int a[100];
    int top = 0;
    public:
    void push(int num);
    int pop();
};

void Stack::push(int num){
    a[top] = num;
    top++;
}

int Stack::pop(){
    int n = a[top-1];
    top--;
    return n;
}

int perform(char ch, int a, int b){
    if(ch=='+'){
        return a+b;
    }
    else if(ch=='-'){
        return a-b;
    }
    else if(ch=='*'){
        return a*b;
    }
    return a/b;
}


void postfix(string exp, int values[]){
    Stack operandStack;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]>=65&&exp[i]<=90){
            operandStack.push(values[exp[i]-65]);
        }
        else if(exp[i]>=97&&exp[i]<=122){
            operandStack.push(values[exp[i]-97]);
        }
        else{
            int b = operandStack.pop();
            int a = operandStack.pop();
            int c = perform(exp[i], a, b);
            operandStack.push(c);
        }
    }
    int result = operandStack.pop();
    cout<<"\nThe result of the postfix expression: "<<result;
}

int main(){
    string exp;
    cout<<"\nEnter the postfix expression(in alphabets): ";
    cin>>exp;
    int values[26];
    for(int i=0;i<26;i++){
        values[i]=0;
    }
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]>=65&&exp[i]<=90){
            if(values[exp[i]-65]==0){
                cout<<"\nEnter the value of "<<exp[i]<<": ";
                cin>>values[exp[i]-65];
            }
        }
        else if(exp[i]>=97&&exp[i]<=122){
            if(values[exp[i]-97]==0){
                cout<<"\nEnter the value of "<<exp[i]<<": ";
                cin>>values[exp[i]-97];
            }
        }
    }
    postfix(exp, values);
}