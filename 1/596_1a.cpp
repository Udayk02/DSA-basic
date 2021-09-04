#include<iostream>
using namespace std;

long long int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int n;
    long long int factorial;
    int option;
    do{
        cout<<"\n1. Factorial\n\n2. Exit\n\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"\n\nEnter a number to get the factorial: ";
            cin>>n;
            factorial = fact(n);
            cout<<"\n\nFactorial of "<<n<<": "<<factorial<<"\n";
            break;
        case 2:
            cout<<"\n\n ## Exiting ## \n\n";
            break;
        default:
            cout<<"\nEnter a valid option !!\n";
            break;
        }
    }while(option!=2);
    return 1;
}