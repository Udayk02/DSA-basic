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

int perform(int a, int b, char ch){
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

bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return true;
    }
    return false;
}

void postfix(int n, char* exp, char a[10], int values[100]){
    Stack s;
    for(int i=0;exp[i]!='\0';i++){
        for(int j=0;j<n;j++){
            if(exp[i]==a[j]){
                cout<<"**"<<a[j]<<values[j]<<"**";
                s.push(values[j]);
                break;
            }
        }
        if(isOperator(exp[i])){
            int b = s.pop();
            int a = s.pop();
            int c = perform(a, b, exp[i]);
            s.push(c);
        }
    }
    int result = s.pop();
    cout<<result;
}

int main(){
    int n;
    cout<<"Enter number of variables: ";
    cin>>n;
    char exp[100];
    char a[n];
    int values[n];
    cout<<"Enter expression: ";
    cin>>exp;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" variable: ";
        cin>>a[i];
        cout<<"Enter it's value: ";
        cin>>values[i];
    }
    postfix(n, exp, a, values);
}