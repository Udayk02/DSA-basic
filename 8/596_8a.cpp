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
    public:
    int position=0;
    void setfirst(Node *tmp);
    void insert_b(Node *tmp);
    void insert_p(Node *tmp);
    void insert_e(Node *tmp);

    void delete_first();
    void delete_b();
    void delete_p();
    void delete_e();
    
    void print();
};

void linkedlist::setfirst(Node *tmp){
    front=rear=tmp;
    position++;
    cout<<"\nInserted\n";
}

void linkedlist::insert_b(Node *tmp){
    tmp->addr=front;
    front=tmp;
    cout<<"\nInserted\n";
}

void linkedlist::insert_p(Node *tmp){
    int pos;
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        cout<<"\nNo such position available yet\nPlease enter a valid position\n";
        insert_p(tmp);
    }
    else{
        if(pos==1){
            insert_b(tmp);
        }
        else if(pos==position){
            insert_e(tmp);
        }
        else{
            int pos1=1;
            Node *tmp1=NULL;
            tmp1 = new Node();
            tmp1 = front;
            while(pos1<pos-1){
                tmp1 = tmp1->addr;
                pos1++;
            }
            tmp->addr = tmp1->addr;
            tmp1->addr = tmp;
            cout<<"\nInserted\n";
        }
    }
}

void linkedlist::insert_e(Node *tmp){
    rear->addr = tmp;
    rear = tmp;
    cout<<"\nInserted\n";
}

void linkedlist::delete_first(){
    cout<<"\nDeleted "<<front->key<<"\n";
    front=rear=NULL;
    position--;
}

void linkedlist::delete_b(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nDeleted "<<front->key<<"\n";
    tmp=front->addr;
    front->addr=NULL;
    delete front;
    front = tmp;
    position--;
}

void linkedlist::delete_p(){
    int pos;
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        cout<<"\nNo such position exists\n";
        delete_p();
    }
    else if(pos==position){
        delete_e();
    }
    else if(pos==1){
        delete_b();
    }
    else{
        int pos1 = 1;
        Node *tmp = NULL;
        tmp = new Node();
        tmp = front;
        Node *tmp1 = NULL;
        tmp1 = new Node();
        while(pos1<pos-1){
            tmp = tmp->addr;
            pos1++;
        }
        tmp1 = tmp->addr;
        cout<<"\nDeleted "<<tmp1->key<<"\n";
        tmp->addr = tmp1->addr;
        tmp1->addr = NULL;
        delete tmp1;
        position--;
    }
}

void linkedlist::delete_e(){
    Node *tmp = NULL;
    tmp = new Node();
    tmp = front;
    cout<<"\nDeleted "<<rear->key<<"\n";
    while(tmp->addr!=rear){
        tmp = tmp->addr;
    }
    tmp->addr = NULL;
    delete rear;
    rear = tmp;
    position--;
}

void linkedlist::print(){
    Node *tmp = NULL;
    tmp = front;
    cout<<"\n";
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp = tmp->addr;
    }
    cout<<"\n";
}

int main(){
    linkedlist ll;
    int option;
    cout<<"\nSingle Linked List implementation\n";
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\n\nSelect an option: ";
        cin>>option;
        switch(option){
            case 1:
                Node *tmp;
                tmp = new Node();
                cout<<"\nEnter a value: ";
                cin>>tmp->key;
                tmp->addr = NULL;
                if(ll.position==0){
                    ll.setfirst(tmp);
                }
                else{
                    int opt;
                    do{
                        ll.position++;
                        cout<<"\n1. Insert at the beginning\n2. Insert at a position\n3. Insert at the end\nSelect an option: ";
                        cin>>opt;
                        switch(opt){
                            case 1:
                                ll.insert_b(tmp);
                                break;
                            case 2:
                                ll.insert_p(tmp);
                                break;
                            case 3:
                                ll.insert_e(tmp);
                                break;
                            default:
                                cout<<"\nChoose a valid option\n";
                        }
                    } while(opt!=1&&opt!=2&&opt!=3);
                }
                break;
            case 2:
                if(ll.position==0){
                    cout<<"\nNo elements found to delete\n";
                }
                else if(ll.position==1){
                    ll.delete_first();
                }
                else{
                    int opt;
                    do{
                        cout<<"\n1. Delete at the beginning\n2. Delete at a position\n3. Delete at the end\nSelect an option: ";
                        cin>>opt;
                        switch(opt){
                            case 1:
                                ll.delete_b();
                                break;
                            case 2:
                                ll.delete_p();
                                break;
                            case 3:
                                ll.delete_e();
                                break;
                            default:
                                cout<<"\nChoose a valid option";
                                break;
                        }
                    } while(opt!=1&&opt!=2&&opt!=3);
                }
                break;
            case 3:
                if(ll.position==0){
                    cout<<"\nNo elements found to print\n";
                }
                else{
                    ll.print();
                }
                break;
            case 4:
                cout<<"\n###Exiting###\n\n";
                break;
            default:
                cout<<"\nChoose a valid option\n";
                break;
        }
    } while(option!=4);
}