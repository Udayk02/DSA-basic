#include<iostream>
using namespace std;

int gcd(int a, int b){
    static int i=1;
    if(i%a==0 && i%b==0){
        int r = i;
        i = 1;
        return (a*b)/r;
    }
    else{
        i++;
        return gcd(a,b);
    }
}


int main(){
    int a, b, opt;
    int result;
    // do{
    //     cout<<"\n1. GCD\n2. Exit\n";
    //     cout<<"\nChoose any of the two options: ";
    //     cin>>opt;
    //     switch (opt)
    //     {
    //     case 1:
            cout<<"\nEnter two numbers to get GCD: ";
            cin>>a;
            cin>>b;
            result = gcd(a, b);
            cout<<"\nThe GCD of two numbers is "<<result<<"\n";
    //         break;
    //     case 2:
    //         cout<<"\n\n***Exting***\n\n";
    //         break;
    //     default:
    //         cout<<"\n\nChoose either 1 or 2: ";
    //         break;
    //     }
    // }while(opt!=2);
    return 1;
}