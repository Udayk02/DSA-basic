#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left, *right;
};

class dll{
    Node *front=NULL, *rear=NULL;
    public:
    int position=0;
    void setfirst(Node *tmp);
    void insert_b(Node *tmp);
    void insert_p(Node *tmp);
    void insert_e(Node *tmp);
    void deletefirst();
    void delete_b();
    void delete_p();
    void delete_e();
    void print_f();
    void print_r();
};

void dll::setfirst(Node *tmp){
    front=tmp;
    rear=tmp;
    position++;
    cout<<"\nInserted\n";
}

void dll::insert_b(Node *tmp){
    tmp->right=front;
    front->left=tmp;
    front=tmp;
    cout<<"\nInserted\n";
}

void dll::insert_p(Node *tmp){
    int pos;
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        cout<<"\nNo such position available\nPlease choose valid position\n";
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
            tmp1=front;
            while(pos1<pos-1){
                tmp1=tmp1->right;
                pos1++;
            }
            tmp->right=tmp1->right;
            tmp1->right->left=tmp;
            tmp1->right=tmp;
            tmp->left=tmp1;
            cout<<"\nInserted\n";
        }
    }
}

void dll::insert_e(Node *tmp){
    rear->right=tmp;
    tmp->left=rear;
    rear=tmp;
    cout<<"\nInserted\n";
}

void dll::deletefirst(){
    cout<<"\nDeleted "<<front->key<<"\n";
    front=rear=NULL;
    position--;
}

void dll::delete_b(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nDeleted "<<front->key<<"\n";
    tmp=front->right;
    tmp->left=NULL;
    front->right=NULL;
    delete front;
    front=tmp;
    position--;
}

void dll::delete_p(){
    int pos;
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        cout<<"\nNo such position exists\nPlease choose valid position\n";
        delete_p();
    }
    else{
        if(pos==1){
            delete_b();
        }
        else if(pos==position){
            delete_e();
        }
        else{
            int pos1=1;
            Node *tmp=NULL;
            tmp = new Node();
            tmp=front;
            Node *tmp1=NULL;
            tmp1 = new Node();
            while(pos1<pos){
                tmp = tmp->right;
                pos1++;
            }
            cout<<"\nDeleted "<<tmp->key<<"\n";
            tmp1=tmp->left;
            tmp1->right=tmp->right;
            tmp->right->left=tmp1;
            tmp->right=tmp->left=NULL;
            delete tmp;
            position--;
        }
    }
}

void dll::delete_e(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nDeleted "<<rear->key<<"\n";
    tmp=rear->left;
    rear->left=NULL;
    tmp->right=NULL;
    delete rear;
    rear=tmp;
    position--;
}

void dll::print_f(){
    Node *tmp=NULL;
    tmp = front;
    cout<<"\n";
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp=tmp->right;
    }
    cout<<"\n";
}

void dll::print_r(){
    Node *tmp=NULL;
    tmp = rear;
    cout<<"\n";
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp = tmp->left;
    }
    cout<<"\n";
}

int main(){
    int option;
    dll ll;
    cout<<"\nDouble Linked List Implementation\n";
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            Node *tmp;
            tmp = new Node();
            cout<<"\nEnter a value: ";
            cin>>tmp->key;
            tmp->left = tmp->right = NULL;
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
                            break;
                    }
                } while(opt!=1&&opt!=2&&opt!=3);
            }
            break;
        case 2:
            if(ll.position==0){
                cout<<"\nNo elements found to delete\n";
            }
            else if(ll.position==1){
                ll.deletefirst();
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
                            cout<<"\nChoose a valid option\n";
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
                int opt;
                do{
                    cout<<"\n1. Print from front\n2. Print from rear\nSelect an option: ";
                    cin>>opt;
                    switch(opt){
                        case 1:
                            ll.print_f();
                            break;
                        case 2:
                            ll.print_r();
                            break;
                        default:
                            cout<<"\nChoose a valid option\n";
                            break;
                    }
                } while(opt!=1&&opt!=2);
            }
            break;
        case 4:
            cout<<"\nExiting\n";
            break;
        default:
            cout<<"\nChoose a valid option\n";
            break;
        }
    } while(option!=4);
}