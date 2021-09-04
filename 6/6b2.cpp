#include<iostream>
using namespace std;

int top = 0;

void push(int*, int);
int pop(int*);
bool isOperator(char);
int perform(int, int, char);
void postfix(int*, int, char*, char*, int*);

int main(){
    int stack[100]={0}, n;
    cout<<"Enter number of variables: ";
    cin>>n;
    char var[n];
    int val[n];
    char exp[100];
    cout<<"Enter expression: ";
    cin>>exp;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<" variable: ";
        cin>>var[i];
        cout<<"Enter it's value: ";
        cin>>val[i];
    }
    postfix(stack, n, exp, var, val);
}

void push(int* stack, int val){
    stack[top] += val;
    top++;
}

int pop(int* stack){
    int n = stack[top-1];
    stack[top-1] = 0;
    top--;
    return n;
}

bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return true;
    }
    return false;
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

void postfix(int stack[], int n, char* exp, char var[], int val[]){
    for(int i=0;exp[i]!='\0';i++){
        for(int j=0;j<n;j++){
            if(exp[i]==var[j]){
                push(stack, val[j]);
                break;
            }
        }
        if(isOperator(exp[i])){
            int b = pop(stack);
            int a = pop(stack);
            int c = perform(a, b, exp[i]);
            push(stack, c);
        }
    }
    int result = pop(stack);
    cout<<"Result of expression: "<<result;
}