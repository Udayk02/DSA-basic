#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left, *right;
};

class dll{
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

void dll::insert_b(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"Enter key value: ";
    cin>>tmp->key;
    tmp->right = tmp->left = NULL;
    if(front==NULL&&rear==NULL){
        front=tmp;
        rear=tmp;
        cout<<"\nInserted";
        position++;
    }
    else{
        tmp->right = front;
        front->left = tmp;
        front = tmp;
        cout<<"\nInserted";
        position++;
    }
}

void dll::insert_p(){
    int pos;
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"\nEnter position: ";
    cin>>pos;
    if(pos>position){
        delete tmp;
        cout<<"\nUpto now No such position exists.\n";
    }
    else{
        if(pos==1){
            delete tmp;
            insert_b();
        }
        else{
            cout<<"\nEnter value: ";
            cin>>tmp->key;
            tmp->left=tmp->right=NULL;
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
            cout<<"\nInserted.\n";
            position++;
        }
    }
}

void dll::insert_e(){
    Node *tmp=NULL;
    tmp = new Node();
    cout<<"Enter key value: ";
    cin>>tmp->key;
    tmp->right = tmp->left = NULL;
    if(front==NULL&&rear==NULL){
        front=tmp;
        rear=tmp;
        cout<<"\nInserted";
        position++;
    }
    else{
        rear->right = tmp;
        tmp->left = rear;
        rear = tmp;
        cout<<"\nInserted";
        position++;
    }
}

void dll::print(){
    if(front==NULL&&rear==NULL){
        cout<<"\nNo elements found to print.\n";
    }
    Node *tmp=NULL;
    tmp = front;
    while(tmp!=NULL){
        cout<<tmp->key<<" ";
        tmp=tmp->right;
    }
}

int main(){
    dll ll;
    int option;
    do{
        cout<<"\nDouble Linked List\n\n1. Insert\n2. Delete\n3. Print\n4. Exit";
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
            int opt1;
            do{
                cout<<"\n1. Print from front\n2. Print from rear\n3. Exit\nSelect an option: ";
                cin>>opt1;
                switch (opt1)
                {
                case 1:
                    // print_f();
                    break;
                case 2:
                    // print_r();
                    break;
                case 3:
                    cout<<"\nExiting\n";
                    break;
                default:
                    cout<<"\nChoose a valid option: ";
                    break;
                }
            } while(opt1!=3);
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