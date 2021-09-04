#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *addr;
};

class linkedlist{
    Node *front=NULL;
    Node *rear=NULL;
    int position=0;
    public:
    void insert_b();
    void insert_p();
    void insert_e();
    void delete_b();
    void delete_p();
    void delete_e();
    void print();
};

void linkedlist::insert_b(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nEnter value: ";
    cin>>tmp->key;
    tmp->addr;
    if(front==NULL&&rear==NULL){
        front=rear=tmp;
        position++;
        cout<<"\nInserted\n";
    }
    else{
        tmp->addr=front;
        front=tmp;
        position++;
        cout<<"\nInserted.\n";
    }
}

void linkedlist::insert_p(){
    int pos;
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        delete tmp;
        cout<<"\nUpto now No such position exists.\n";
        return;
    }
    else{
        if(pos==1){
            delete tmp;
            insert_b();
            return;
        }
        else{
            cout<<"\nEnter value: ";
            cin>>tmp->key;
            tmp->addr=NULL;
            int pos1=1;
            Node *tmp1=NULL;
            tmp1 = new Node();
            tmp1=front;
            while(pos1<pos-1){
                tmp1=tmp1->addr;
                pos1++;
            }
            tmp->addr=tmp1->addr;
            tmp1->addr=tmp;
            cout<<"\nInserted.\n";
            position++;
        }
    }
}

void linkedlist::insert_e(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nEnter value: ";
    cin>>tmp->key;
    tmp->addr;
    if(front==NULL&&rear==NULL){
        front=rear=tmp;
        position++;
        cout<<"\nInserted\n";
    }
    else{
        rear->addr=tmp;
        rear=tmp;
        position++;
        cout<<"\nInserted.\n";
    }
}

void linkedlist::delete_b(){
    if(front==NULL&&rear==NULL){
        cout<<"\nNo elements to delete.\n";
        return;
    }
    else if(front->addr==NULL){
        front=rear=NULL;
        cout<<"\nDeleted\n";
        position--;
    }
    else{
        Node *tmp=NULL;
        tmp=front;
        tmp=front->addr;
        delete front;
        front=tmp;
        cout<<"\nDeleted\n";
        position--;
    }
}

void linkedlist::delete_p(){
    int pos;
    Node *tmp=NULL;
    tmp = new Node();
    if(front==NULL&&rear==NULL){
        cout<<"\nNo elements to delete.\n";
        return;
    }
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        delete tmp;
        cout<<"\nUpto now NO such position exists.\n";
        return;
    }
    else{
        if(pos==1){
            delete tmp;
            delete_b();
            return;
        }
        else{
            tmp=front;
            Node *tmp1=NULL;
            tmp1 = new Node();
            int pos1=1;
            while(pos1<pos-1){
                tmp=tmp->addr;
                pos1++;
            }
            tmp1=tmp->addr;
            tmp->addr=tmp1->addr;
            delete tmp1;
            cout<<"\nDeleted\n";
            position--;
        }
    }
}

void linkedlist::delete_e(){
    if(front==NULL&&rear==NULL){
        cout<<"\nNo elements to delete\n";
        return;
    }
    else if(front->addr==NULL){
        front=rear=NULL;
        cout<<"\nDeleted\n";
        position--;
    }
    else{
        Node *tmp=NULL;
        tmp = new Node();
        tmp=front;
        while(tmp->addr!=rear){
            tmp=tmp->addr;
        }
        tmp->addr=NULL;
        delete rear;
        rear=tmp;
        cout<<"\nDeleted\n";
        position--;
    }
}

void linkedlist::print(){
    if(front==NULL&&rear==NULL){
        cout<<"\nNo elements found to print.\n";
    }
    Node *tmp=NULL;
    tmp = front;
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp=tmp->addr;
    }
}

int main(){
    linkedlist ll;
    int option;
    do{
        cout<<"\nLinked List\n\n1. Insert\n2. Delete\n3. Print\n4. Exit";
        cout<<"\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            int opt;
            do{
                cout<<"\n1. Insert at the beginning\n2. Insert at a position\n3. Insert at the end\n4. Exit\nSelect an option: ";
                cin>>opt;
                switch (opt)
                {
                case 1:
                    ll.insert_b();
                    break;
                case 2:
                    ll.insert_p();
                    break;
                case 3:
                    ll.insert_e();
                    break;
                case 4:
                    cout<<"\nExiting\n";
                default:
                    cout<<"\nSelect a valid option: ";
                    break;
                }
            } while(opt!=4);
            break;
        case 2:
            int opt1;
            do{
                cout<<"\n1. Delete at the beginning\n2. Delete at a position\n3. Delete at the end\n4. Exit\nSelect an option: ";
                cin>>opt1;
                switch (opt1)
                {
                case 1:
                    ll.delete_b();
                    break;
                case 2:
                    ll.delete_p();
                    break;
                case 3:
                    ll.delete_e();
                    break;
                case 4:
                    cout<<"\nExiting\n";
                default:
                    cout<<"\nSelect a valid option: ";
                    break;
                }
            } while(opt1!=4);
            break;
        case 3:
            ll.print();
            break;
        case 4:
            cout<<"\nExiting Bye Bye !\n";
            break;
        default:
            cout<<"\nPlease choose a valid option.\n";
            break;
        }
    } while(option!=4);
}