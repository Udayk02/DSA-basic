#include<iostream>
using namespace std;

void leftrotate(int n, int a[]){
    int x = a[0], i;
    for(i=0;i<n-1;i++){
        a[i] = a[i+1];
    }
    a[i] = x;
}

void rightrotate(int n, int a[]){
    int x = a[n-1], i;
    for(i=n-1;i>=0;i--){
        a[i] = a[i-1];
    }
    a[0] = x;
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int option;
    do{
        cout<<"\n1. Left\n2. Right\n3. Print\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            leftrotate(n, a);
            break;
        case 2:
            rightrotate(n, a);
            break;
        case 3:
            cout<<"\nArray: ";
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";                
            }
            break;
        default:
            break;
        }
    } while(option!=3);
}