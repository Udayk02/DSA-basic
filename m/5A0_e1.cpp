// 1. Write a program to implement double stack.
#include<iostream>
using namespace std;
class dstack{
    int top,Max,ntop,count;
    int countA,countB;
    int a[];
    public:
    void pushA(int);
    void pushB(int);
    void popA();
    void popB();
    void printA();
    void printB();
    dstack();
};
dstack :: dstack(){
    top=-1;
    count=0;
    cout<<"Enter size of stack:";
    cin>>Max;
    ntop=Max;
    countA=0;
    countB=0;
}
void dstack::pushA(int x){
    if(count==Max){
        cout<<"Stack overflow\n";
        return;
    }
    a[++top]=x;
    count++;
    countA++;
}
void dstack::pushB(int x){
    if(count==Max){
        cout<<"Stack overflow\n";
        return;
    }
    a[--ntop]=x;
    count++;
    countB++;
}
void dstack:: popA(){
    if(count==0){
        cout<<"Stack Underflow\n";
        return;
    }
    else if(countA==0){
        cout<<"Forward stack is empty\n";
        return;
    }
    top--;
    count--;
    countA--;
}
void dstack::popB(){
    if(count==0){
        cout<<"Stack Underflow\n";
        return;
    }
    else if(countB==0){
        cout<<"Backward stack is empty\n";
        return;
    }
    ntop++;
    count--;
    countB--;
}
void dstack::printA(){
    if(count==0){
        cout<<"No elements exists\n";
        return;
    }
    else if(countA==0){
        cout<<"Forward stack is empty\n";
        return;
    }
    for(int i=0;i<=top;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void dstack ::printB(){
    if(count==0){
        cout<<"No elements exists\n";
        return;
    }
    else if(countB==0){
        cout<<"Backward stack is empty\n";
        return;
    }
    for(int i=Max-1;i<=ntop;i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    dstack d;
    int op,oop,ops,op1;
    while(true){
        cout<<"1.Insert 2.Delete 3.Print 4.Exit\n";
        cout<<"Select an option:";
        cin>>op;
        switch(op){
            case 1:do{
                        cout<<"1.Insert in forward Stack 2.Insert in backward Stack\n";
                        cout<<"Select an option:";
                        cin>>oop;
                        int x;
                        cout<<"Enter a value:";
                        cin>>x;
                        switch(oop){
                            case 1:d.pushA(x);
                                    break;
                            case 2:d.pushB(x);
                                    break;
                            default:cout<<"Select proper option\n";
                        }
            }while(oop>2);
            break;
            case 2:do{
                        cout<<"1.Delete from forward Stack 2.Delete from backward Stack\n";
                        cout<<"Select an option:";
                        cin>>ops;
                        switch(oop){
                            case 1:d.popA();
                                    break;
                            case 2:d.popB();
                                    break;
                            default:cout<<"Select proper option\n";
                        }
                    }while(ops>2);
                    break;
            case 3:do{
                        cout<<"1.Print forward stack 2.Print Backward Stack\n";
                        cout<<"Select an option:";
                        cin>>op1;
                        switch(op1){
                            case 1 :d.printA();
                                break;
                            case 2: d.printB();
                                    break;
                            default:cout<<"Select proper option\n";
                        }
                }while(op1>2);
                break;
            case 4:exit(0);
            default:cout<<"Select proper option\n";

        }
    }
}