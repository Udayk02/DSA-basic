#include<iostream>
using namespace std;

int main(){
    int n, offset = -1, fib0, fib1, fib2, search, k;
    cout<<"\nFibonacci Search\n\nEnter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter elements sorted: ";
    for(int i=0;i<n;i++){
       cin>>a[i];
    }
    cout<<"\nEnter search element: ";
    cin>>search;
    fib0 = 0;fib1 = 1;fib2 = 1;
    while(fib2<=n){
        fib0 = fib1 + fib2;
        fib1 = fib0 + fib2;
        fib2 = fib1 + fib0;
    }
    while(fib2>1){
        k = (offset+fib0)<(n-1)?(offset+fib0):(n-1);
        if(a[k]==search){
            cout<<"Element found at "<<k;
            break;
        }
        else if(a[k]>search){
            fib2 = fib0;
            fib1 = fib1 - fib0;
            fib0 = fib2 - fib1;
        }
        else if(a[k]<search){
            offset = offset + fib0;
            fib2 = fib1;
            fib1 = fib0;
            fib0 = fib2 - fib1;
        }
    }
    if(fib2<=1){
        cout<<"NO element found";
    }
    return 1;
}