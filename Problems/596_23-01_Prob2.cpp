#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array: ";
    for(int i = 0;i<n;++i){
        cin>>arr[i];
    }
    int query;
    cout<<"Enter queries: ";
    cin>>query;
    for(int m = 1;m<=query;++m){
        cout<<"\nEnter query "<<m<<": ";
        int option, i, j, x;
        cin>>option>>i>>j;
        x = i;
        switch(option){
            case 1:{
                if(i<=j){
                    int arr1[n], k = 0;
                    for(k, x;x<=j;++x, ++k)         arr1[k] = arr[x];
                    for(int m = 0;m<i;++m, ++k)     arr1[k] = arr[m];
                    for(int m = j+1;m<n;++m, ++k)   arr1[k] = arr[m];
                    for(int m = 0;m<n;++m)          arr[m] = arr1[m];
                    for(int m = 0;m<n;++m)          cout<<arr[m]<<" ";
                }
                break;    
            }
            case 2:{
                if(i<=j){
                    int arr1[n], k = 0;
                    for(int m = 0;m<i;++m, ++k)     arr1[k] = arr[m];
                    for(int m = j+1;m<n;++m, ++k)   arr1[k] = arr[m];
                    for(k, x;x<=j;++x, ++k)         arr1[k] = arr[x];
                    for(int m = 0;m<n;++m)          arr[m] = arr1[m];
                    for(int m = 0;m<n;++m)          cout<<arr[m]<<" ";
                }
                break;
            }
            default:
                cout<<"Please choose option 1 and 2\n";
                break;
        }   
    }
}