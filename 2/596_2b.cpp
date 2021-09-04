#include<iostream>
using namespace std;

int main(){
    int n, search, first, middle, last;
    cout<<"\nBinary Search\n\nEnter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter elements sorted: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nEnter search element: ";
    cin>>search;
    first = 0;
    last = n-1;
    middle = (first+last)/2;

    while(first<=last){
        if(search>a[middle]){
            first = middle + 1;
        }
        else if(search == a[middle]){
            cout<<"\nFound at index "<<middle;
            break;
        }
        else{
            last = middle - 1;
        }
        middle = (first+last)/2;
    }
    if(first>last){
        cout<<"Element not found !";
    }
    return 1;
}