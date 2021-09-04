#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *addr;
};

class ll{
    Node *front = NULL;
    Node *rear = NULL;
    public:
    void setfirst(Node*);
    void insert(int, Node*);
    void bubblesort1(int);
    void print();
};

void ll::setfirst(Node *tmp){
    front = rear = tmp;
}

void ll::insert(int i, Node *tmp){
    rear->addr = tmp;
    rear = tmp;
}

void ll::bubblesort1(int size){
    Node *tmp = NULL;
    tmp = new Node();
    for(int i = 1;i<=size;++i){
        tmp = front;
        bool s = true;
        for(int j = 1;j<=(size-i);++j){
            if(tmp->key>tmp->addr->key){
                int temp = tmp->key;
                tmp->key = tmp->addr->key;
                tmp->addr->key = temp;
                s = false;
            }
            tmp = tmp->addr;
        }
        if(s){
            break;
        }
    }
}

void ll::print(){
    cout<<"Linked list: ";
    Node *tmp = NULL;
    tmp = front;
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp = tmp->addr;
    }
    cout<<"\n";
}

int main(){
    ll l;
    int size;
    cout<<"\nEnter your linked list size: ";
    cin>>size;
    for(int i = 1;i<=size;++i){
        Node *tmp = NULL;
        tmp = new Node();
        cout<<"Enter value "<<i<<": ";
        cin>>tmp->key;
        tmp->addr = NULL;
        if(i==1){
            l.setfirst(tmp);
        }
        else{
            l.insert(i, tmp);
        }
    }
    l.print();
    l.bubblesort1(size);
    cout<<"\nAfter sorting ";
    l.print();
}