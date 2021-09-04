#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in sorted order: ";
    for(int i=0;i<n;++i){
        cin >> arr[i];
    }
    int search; 
    cout<<"Enter the search elements: ";
    cin>> search;
    int f0 = 0, f1 = 1, f2 = 1;
    while(f2 <= n){
        f0 = f1 + f2;
        f1 = f0 + f2;
        f2 = f0 + f1;
    }
    int offset = -1, k;
    while(f2>1){
        k = (offset+f0)<(n-1)?offset+f0:n-1;
        if(arr[k]==search){
            cout<<"Elements found at "<<k;
            break;
        }
        else if(arr[k]<search){
            offset += f0;
            f2 = f1;
            f1 = f0;
            f0 = f2 - f1;
        }
        else if(arr[k]>search){
            f2 = f0;
            f1 = f1 - f0;
            f0 = f2 - f1;
        }
    }
    if(f2<=1){
        cout<<"No element found.";
    }
}