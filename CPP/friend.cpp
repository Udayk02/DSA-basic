#include<iostream>
using namespace std;

class A{
    int i, j;
    public:
        void fun1(){
            cout<<"In function fun1()";
        }
        void setij(){
            i = 10;
            j = 20;
        }
        friend class B;
};

class B{
    int b;
    public:
        void printAi(A &x){
            cout<<x.i<<" ";
        }
        void printAj(A &y){
            cout<<y.j<<" ";
        }
};

int main(){
    A a1;
    B b1;
    a1.setij();
    b1.printAi(a1);
    b1.printAj(a1);
}