#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *addr;
};

int main(){
    Node *tmp=NULL;
    tmp = new Node();
    Node *front=NULL;
    front = new Node();
    front->key=10;
    front->addr=tmp;
    tmp->key=20;
    tmp->addr=NULL;
    cout<<tmp->key;
    cout<<&tmp;
    // Node *tmp1=NULL;
    // tmp1 = new Node();
    // tmp1->addr=&tmp;
    // cout<
}