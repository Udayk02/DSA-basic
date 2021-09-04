#include<iostream>
using namespace std;

int main(){
    int limit;
    cout<<"Enter limit: ";
    cin>>limit;
    int count = 0;
    for(int a = 1;a<=limit;++a){
        for(int b = 1;b<=limit;++b){
            for(int c = 1;c<=limit;++c){
                if(((a*a)+(b*b)-(c*c))==0){
                    // cout<<"a: "<<a<<"b: "<<b<<"c: "<<c<<"\n";
                    count++;
                }
            }
        }
    }
    cout<<"Total triplets within limit: "<<count;
}