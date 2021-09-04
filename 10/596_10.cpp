#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left = NULL, *right = NULL;
};

class BST{
    public:
    Node *root = NULL;
    Node* insert(Node*, Node*);
    Node* deleteNode(Node*, int);
    Node* deleteKey(Node*);
    int search(Node*, int, int);
    int max(Node*);
    void in_order(Node*);
    void pre_order(Node*);
    void post_order(Node*);
    friend void print(BST);
};

Node* BST::insert(Node* root, Node* tmp){
    if(root==NULL){
        root=tmp;
    }
    else{
        if(root->key>tmp->key){
            root->left = insert(root->left, tmp);
        }
        else if(root->key<tmp->key){
            root->right = insert(root->right, tmp);
        }
        else{
            cout<<"\nElement already inserted. No duplicates allowed.\nNot";
        }
    }
    return root;
}

Node* BST::deleteNode(Node* root, int k){
    if(root==NULL){
        cout<<"\nValue not found to delete\nNot";
    }
    else if(root->key>k){
        root->left = deleteNode(root->left, k);
    }
    else if(root->key<k){
        root->right = deleteNode(root->right, k);
    }
    else{
        root = deleteKey(root);
    }
    return root;
}

Node* BST::deleteKey(Node* tmp){
    if((tmp->left!=NULL&&tmp->right==NULL)||(tmp->left==NULL&&tmp->right!=NULL)){
        if(tmp->left==NULL){
            return tmp->right;
        }
        else{
            return tmp->left;
        }
    }
    else if(tmp->left!=NULL&&tmp->right!=NULL){
        int r = max(tmp->left);
        tmp->key = r;
        tmp->left = deleteNode(tmp->left, r);
        return tmp;
    }
    return NULL;
}

/*
Node* BST::deleteKey(Node* tmp){
    if(tmp->left==NULL&&tmp->right==NULL){
        return NULL;
    }
    else if(tmp->left==NULL||tmp->right==NULL){
        if(tmp->left==NULL){
            return tmp->right;
        }
        else{
            return tmp->left;
        }
    }
    else{
        int r = max(tmp->left);
        tmp->key = r;
        tmp->left = deleteNode(tmp->left, r);
        return tmp;
    }
}
*/

int BST::max(Node* tmp){
    while(tmp->right!=NULL){
        tmp = tmp->right;
    }
    return tmp->key;
}

void BST::in_order(Node* tmp){
    if(tmp!=NULL){
        in_order(tmp->left);
        cout<<tmp->key<<" ";
        in_order(tmp->right);
    }
}

void BST::pre_order(Node* tmp){
    if(tmp!=NULL){
        cout<<tmp->key<<" ";
        pre_order(tmp->left);
        pre_order(tmp->right);
    }
}

void BST::post_order(Node* tmp){
    if(tmp!=NULL){
        post_order(tmp->left);
        post_order(tmp->right);
        cout<<tmp->key<<" ";
    }
}

int BST::search(Node* root, int k, int position){
    if(root==NULL){
        return 0;
    }
    else if(root->key==k){
        return position;
    }
    else if(root->key>k){
        position = search(root->left, k, position*2);
    }
    else if(root->key<k){
        position = search(root->right, k, position*2+1);
    }
    return position;
}

void print(BST bt){
    int option;
    do
    {
        cout<<"\n1. Print InOrder\n2. Print PreOrder\n3. Print PostOrder\n4. Return\n\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            cout<<"\nInOrder of the Binary search tree: ";
            bt.in_order(bt.root);
            break;
        case 2:
            cout<<"\nPreOrder of the Binary search tree: ";
            bt.pre_order(bt.root);
            break;
        case 3:
            cout<<"\nPostOrder of the Binary search tree: ";
            bt.post_order(bt.root);
            break;
        case 4:
            break;
        default:   
            cout<<"\nChoose a valid option.\n";
            break;
        }
    } while (option!=4);
}

int main(){
    int option, k, position = 1;
    BST bt;
    Node *tmp = NULL;
    cout<<"\nBinary Search Tree Implementation\n";
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Search\n4. Print\n5. Exit\n\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            tmp = new Node();
            cout<<"\nEnter the value: ";
            cin>>tmp->key;
            tmp->left = tmp->right = NULL;
            bt.root = bt.insert(bt.root, tmp);
            cout<<"\nInserted\n";
            break;
        case 2:
            if(bt.root==NULL){
                cout<<"\nNo values to delete\n";
            }
            else{
                cout<<"\nEnter the value to be deleted: ";
                cin>>k;
                bt.root = bt.deleteNode(bt.root, k);
                cout<<"\nDeleted\n";
            }
            break;
        case 3:
            cout<<"\nEnter the value to be searched: ";
            cin>>k;
            position = bt.search(bt.root, k, position);
            if(position==0){
                cout<<"\nValue not found\n";
                position = 1;
            }
            else{
                cout<<"\nValue found at position "<<position<<"\n";
                position = 1;
            }
            break;
        case 4:
            if(bt.root==NULL){
                cout<<"\nNo values to print\n";
            }
            else
                print(bt);
            break;
        case 5:
            cout<<"\nExiting\n";
            break;
        default:
            cout<<"\nChoose a valid option.\n";
            break;
        }
    } while(option!=5);
}