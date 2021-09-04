#include<iostream>
using namespace std;

class Stack{
    public:
    int a[100];
    int top = 0;
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

void factorial(int n){
    if(n==0){
        cout<<"\nThe factorial: 1";
        return;
    }
    Stack num;
    for(int i=1;i<=n;i++){
        if(num.top==0){
            num.push(i);
        }
        else{
            int x = num.pop();
            num.push(x*i);
        }
    }
    int result = num.pop();
    cout<<"\nThe factorial: "<<result;
}

int main(){
    int n;
    cout<<"\nFactorial using stack\n(Unfortunately this program supports between numbers 0 and 12 only)\n";
    cout<<"\nEnter a number to get it's factorial: ";
    cin>>n;
    factorial(n);
    return 1;
}   