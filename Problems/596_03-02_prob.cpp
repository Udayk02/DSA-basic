#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *addr;
};

Node* temp = NULL;

class linkedlist{
    Node *front = NULL;
    Node *rear = NULL;
    public:
    void insert(Node*);
    void print();
};

void linkedlist::insert(Node *tmp){
    if(front==NULL){
        front = rear = tmp;
        temp = rear;
    }
    else if(temp->key==tmp->key){
        return;
    }
    else{
        rear->addr = tmp;
        rear = tmp;
        temp = rear;
    }
}

void linkedlist::print(){
    Node *tmp = NULL;
    tmp = front;
    cout<<"\nLinked list in sorted and unique: ";
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp = tmp->addr;
    }
}

int main(){
    linkedlist ll;
    int option;
    do{
        cout<<"\n1. Insert(in sorted format only)\t2. Print\t3. Exit\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:{
            Node *tmp = NULL;
            tmp = new Node();
            cout<<"Enter a value: ";
            cin>>tmp->key;
            tmp->addr = NULL;
            ll.insert(tmp);
            break;

        }
        case 2:
            ll.print();
            break;
        case 3:
            break;
        default:
            cout<<"\nEnter a valid option";
            break;
        }
    } while(option!=3);
}