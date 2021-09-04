#include<iostream>
using namespace std;

int main(){
    int opt;
    int n;
    int a[100], search;
    // do{
    //     cout<<"\n1. Perform Linear Search\n2. Exit\n";
    //     cout<<"\nChoose an option: ";
    //     cin>>opt;

    //     switch (opt)
    //     {
    //         case 1:
                
                cout<<"\nEnter number of elements: ";
                cin>>n;
                
                cout<<"\nEnter the elements: ";
                for(int i=0;i<n;i++){
                    cin>>a[i];
                }    
                cout<<"\nEnter the search element: ";
                cin>>search;
                for(int i=0;i<=n;++i){
                    if(a[i]==search){
                        cout<<"\n\nFound "<<search<<" at index "<<i<<"\n\n";
                        break;
                    }
                    else if(i==n){
                        cout<<"\n\nElement not found.\n\n";
                    }
                }
    //             break;
    //         case 2:
    //             cout<<"\n\n*** Exiting ***\n\n";
    //             break;
    //         default:
    //             cout<<"\n\nChoose either 1 or 2.\n\n";
    //             break;
    //     }
    // }while(opt!=2);
    return 1;
}
