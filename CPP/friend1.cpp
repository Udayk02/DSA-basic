#include<iostream>
using namespace std;

class A;
class B{
    int b;
    public:
        void printAi(A &x);
        void printAj(A &y){
            // cout<<y.j<<" ";
        }
};

class A{
    int i, j;
    public:
        void setij(){
            i = 10; j = 20;
        }
        friend void B::printAi(A &x);
};

void B::printAi(A &x){
    cout<<x.i<<" ";
}