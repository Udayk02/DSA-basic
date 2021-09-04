#include<iostream>
using namespace std;

int main(){
    bool s = false;
    for(int i = 0;s;++i){
        if(i==5){
            break;
        }
        cout<<i<<" ";
    }
}