#include<iostream>
using namespace std;

int main(){
    int search, f0=0, f1=1, f2=1, o=-1, n, k;
    cout<<"Enter number of elements:";
    cin>>n;
    int a[n];
    cout<<"Enter Elements in ascending order:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter search element:";
    cin>>search;
    for(int i=0;i<n;i++){
        f0 = f1 + f2;
        f1 = f2 + f0;
        f2 = f1 + f0;
    }
    while(f2>1){
        if((o+f0)<(n-1)){
            k = o+f0;
        }
        else{
            k = n-1;
        }
        if(a[k]==search){
            cout<<"Element found at "<<k;
            break;
        }
        else if(a[k]<search){
            o = o + f0;
            f2 = f1;
            f1 = f0;
            f0 = f2 - f1;
        }
        else{
            f2 = f0;
            f1 = f1 - f0;
            f0 = f2 - f1;
        }
    }
}