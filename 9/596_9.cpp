#include<iostream>
#include<math.h>
using namespace std;

class BT{
    int arr[100];
    int max, height;
    BT();
    friend void create();
    void insert(int, int);
    void in_order(int);
    void pre_order(int);
    void post_order(int);
};

BT::BT(){
    cout<<"\nEnter the height of your binary tree: ";
    cin>>height;
    max = pow(2, height+1) - 1;
    for(int i=0;i<=max;i++){
        arr[i] = -1;
    }
}

void BT::insert(int value, int parent){
    if(arr[parent]==-1){
        cout<<"\nParent Node is empty. Value not inserted\n";
    }
    else if(parent>(pow(2, (height-1))-1)){
        cout<<"\nYou can't insert children to that parent node according to the height given.\n";
    }
    else if(arr[parent*2]==-1&&arr[parent*2+1]!=-1){
        cout<<"\nLeft position of the parent node is available. Value inserted.\n";
        arr[parent*2] = value;
    }
    else if(arr[parent*2]!=-1&&arr[parent*2+1]==-1){
        cout<<"\nRight position of the parent node is available. Value inserted.\n";
        arr[parent*2+1] = value;
    }
    else{
        int option;
        do{
            cout<<"\nBoth left and right positions are available\n1. Left\n2. Right\nChoose left or right: ";
            cin>>option;
            switch(option){
                case 1:
                    arr[parent*2] = value;
                    cout<<"\nValue inserted at left of the parent node.\n";
                    break;
                case 2:
                    arr[parent*2+1] = value;
                    cout<<"\nValue inserted at right of the parent node.\n";
                    break;
                default:
                    cout<<"\nChoose a valid option\n";
                    break;
            }
        } while(option!=1&&option!=2);
    }
}

void BT::in_order(int i){
    if(arr[2*i]!=-1)
        in_order(2*i);
    cout<<arr[i]<<" ";
    if(arr[2*i+1]!=-1)
        in_order(2*i+1);
}

void BT::pre_order(int i){
    cout<<arr[i]<<" ";
    if(arr[2*i]!=-1)
        pre_order(2*i);
    if(arr[2*i+1]!=-1)
        pre_order(2*i+1);
}

void BT::post_order(int i){
    if(arr[2*i]!=-1)
        post_order(2*i);
    if(arr[2*i+1]!=-1)
        post_order(2*i+1);
    cout<<arr[i]<<" ";
}

void create(){
    BT bt;
    cout<<"\nEnter the root key: ";
    cin>>bt.arr[1];
    cout<<"\nRoot key inserted\n";
    int option;
    do{
        cout<<"\n\n1. Insert\n2. Print InOrder\n3. Print PreOrder\n4. Print PostOrder\n5. Delete the binary tree and exit\n\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            int value, p_node;
            cout<<"\nEnter value to be inserted: ";
            cin>>value;
            cout<<"\nEnter parent node position: ";
            cin>>p_node;
            bt.insert(value, p_node);
            break;
        case 2:
            cout<<"\nInOrder of the binary tree: \n";
            bt.in_order(1);
            break;
        case 3:
            cout<<"\nPreOrder of the binary tree: \n";
            bt.pre_order(1);
            break;
        case 4:
            cout<<"\nPostOrder of the binary tree: \n";
            bt.post_order(1);
            break;
        case 5:
            cout<<"\nDeleted the entire binary tree and exiting...\n";
            bt.arr[bt.max] = {-1};
            break;
        default:
            cout<<"\nPlease choose a valid option.\n";
            break;
        }
    } while(option!=5);
}

int  main(){
    cout<<"\nBinary Tree Implementation\n";
    int option;
    do{
        cout<<"\n1. Create a binary tree\n2. Exit\n";
        cout<<"\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            create();
            break;
        case 2:
            cout<<"\nExiting\n";
            break;
        default:
            cout<<"\nPlease choose a valid option.\n";
            break;
        }
    } while(option!=2);
}