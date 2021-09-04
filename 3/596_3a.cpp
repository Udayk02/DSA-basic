#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"\nBubble Sort\n\nEnter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        bool s = true;
        for(int j=0;j<(n-i-1);j++){
            if(a[j]>a[j+1]){
                int k = a[j+1];
                a[j+1] = a[j];
                a[j] = k;
                s = false;
            }
        }
        if(s){
            break;
        }
    }
    cout<<"\nElements in sorted order: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 1;
}