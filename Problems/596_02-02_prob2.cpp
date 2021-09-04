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
    void bubblesort2(int);
    void print();
};

void ll::setfirst(Node *tmp){
    front = rear = tmp;
}

void ll::insert(int i, Node *tmp){
    rear->addr = tmp;
    rear = tmp;
}

void ll::bubblesort2(int size){
    Node *tmp = NULL, *tmp1 = NULL, *tmp2 = NULL;
    tmp = new Node();
    tmp1 = new Node();
    tmp2 = new Node();
    for(int i = 1;i<=size;++i){
        tmp = front; tmp1 = tmp->addr; tmp2 = tmp1->addr;
        bool s = true;
        for(int j = 1;j<=(size-i);++j){
            if(j==1){
                if(tmp->key>tmp1->key){
                    tmp->addr = tmp2;
                    tmp1->addr = tmp;
                    front = tmp1;
                    s = false;
                    tmp = front; tmp1 = tmp->addr; tmp2 = tmp1->addr;
                }
            }
            else if(tmp1->key>tmp2->key){
                tmp->addr = tmp2;
                tmp1->addr = tmp2->addr;
                tmp2->addr = tmp1;
                s = false;
                tmp = tmp2; tmp2 = tmp1->addr;
            }
            else{
                tmp = tmp1; tmp1 = tmp->addr; tmp2 = tmp1->addr;
            }
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
    l.bubblesort2(size);
    cout<<"\nAfter sorting ";
    l.print();
}