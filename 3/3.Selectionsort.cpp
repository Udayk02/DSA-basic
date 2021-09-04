#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" of elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int l=i+1;
        for(int j=i+1;j<n;j++){
            if(a[j+1]<a[j]){
                l=j+1;
            }
        }
        if(a[l]<a[i]){
            int temp=a[i];
            a[i]=a[l];
            a[l]=temp;
        }
    }
    cout<<"Elements sorted: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}