#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left = NULL, *right = NULL;
    int ht;
};

class rotation{
    public:
    Node* leftrotate(Node*);
    Node* rightrotate(Node*);
};

class AVL : public rotation{
    public:
    Node *root = NULL;
    Node* insert(Node*, Node*);
    Node* deleteNode(Node*, int);
    Node* deleteKey(Node*);
    int max(Node*);
    int height(Node*);
    int bf(Node*);
    void in_order(Node*);
    void pre_order(Node*);
    void post_order(Node*);
    friend void print(AVL);
};

int AVL::height(Node *tmp){
    int h;
    if(tmp->left==NULL&&tmp->right==NULL)   return 0;
    else if(tmp->left==NULL&&tmp->right!=NULL)  h = 1 + tmp->right->ht;
    else if(tmp->left!=NULL&&tmp->right==NULL)  h = 1 + tmp->left->ht;
    else    h = tmp->left->ht<tmp->right->ht?1 + tmp->right->ht:1 + tmp->left->ht;
    return h;
}

int AVL::bf(Node *tmp){
    int h;
    if(tmp->left==NULL&&tmp->right==NULL)   return 0;
    else if(tmp->left==NULL&&tmp->right!=NULL)  h = -(1 + tmp->right->ht);
    else if(tmp->left!=NULL&&tmp->right==NULL)  h = 1 + tmp->left->ht;
    else    h = tmp->left->ht - tmp->right->ht;
    return h;
}

Node* AVL::insert(Node *root, Node *tmp){
    if(root==NULL){
        root = tmp;
    }
    else if(root->key>tmp->key){
        root->left = insert(root->left, tmp);
        if(bf(root)==2){
            if(root->left->key>tmp->key){
                root = rightrotate(root);
                root->right->ht = height(root->right);
            }
            else{
                root->left = leftrotate(root->left);
                root = rightrotate(root);
                root->left->ht = height(root->left);
                root->right->ht = height(root->right);
            }
        }
    }
    else if(root->key<tmp->key){
        root->right = insert(root->right, tmp);
        if(bf(root)==-2){
            if(root->right->key<tmp->key){
                root = leftrotate(root);
                root->left->ht = height(root->left);
            }
            else{
                root->right = rightrotate(root->right);
                root = leftrotate(root);
                root->left->ht = height(root->left);
                root->right->ht = height(root->right);
            }
        }
    }
    else{
        cout<<"\nElement already exists\nNot";
    }
    root->ht = height(root);
    return root;
}

Node* rotation::leftrotate(Node *tmp){
    Node *a = NULL;
    a = tmp->right;
    tmp->right = a->left;
    a->left = tmp;
    return a;
}

Node* rotation::rightrotate(Node *tmp){
    Node *a = NULL;
    a = tmp->left;
    tmp->left = a->right;
    a->right = tmp;
    return a;
}

Node* AVL::deleteNode(Node *root, int k){
    if(root==NULL){
        cout<<"\nValue not found to delete\nNot";
    }
    else if(root->key>k){
        root->left = deleteNode(root->left, k);
        if(bf(root)==-2){
            if(bf(root->right)==0||bf(root->right)==-1){
                root = leftrotate(root);
                root->left->ht = height(root->left);
            }
            else if(bf(root->right)==1){
                root->right = rightrotate(root->right);
                root = leftrotate(root);
                root->left->ht = height(root->left);
                root->right->ht = height(root->right);
            }
        }
    }
    else if(root->key<k){
        root->right = deleteNode(root->right, k);
        if(bf(root)==2){
            if(bf(root->left)==0||bf(root->left)==1){
                root = rightrotate(root);
                root->right->ht = height(root->right);
            }
            else if(bf(root->right)==-1){
                root->left = leftrotate(root->left);
                root = rightrotate(root);
                root->left->ht = height(root->left);
                root->right->ht = height(root->right);
            }
        }
    }
    else{
        root = deleteKey(root);
    }
    if(root!=NULL){
        root->ht = height(root);
    }
    return root;
}

Node* AVL::deleteKey(Node *tmp){
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

int AVL::max(Node *tmp){
    while(tmp->right!=NULL){
        tmp = tmp->right;
    }
    return tmp->key;
}

void AVL::in_order(Node *tmp){
    if(tmp!=NULL){
        in_order(tmp->left);
        cout<<tmp->key<<" ";
        in_order(tmp->right);
    }
}

void AVL::pre_order(Node *tmp){
    if(tmp!=NULL){
        cout<<tmp->key<<" ";
        pre_order(tmp->left);
        pre_order(tmp->right);
    }
}

void AVL::post_order(Node *tmp){
    if(tmp!=NULL){
        post_order(tmp->left);
        post_order(tmp->right);
        cout<<tmp->key<<" ";
    }
}

void print(AVL a){
    int option;
    do{
        cout<<"\n1. In Order\n2. Pre Order\n3. Post Order\n4. Exit\nSelect an option: ";
        cin>>option;
        switch(option){
            case 1:
                cout<<"\n";     a.in_order(a.root);     cout<<"\n";
                break;
            case 2:
                cout<<"\n";     a.pre_order(a.root);    cout<<"\n";
                break;
            case 3:
                cout<<"\n";     a.post_order(a.root);   cout<<"\n";
                break;
            case 4:
                break;
            default:
                cout<<"\nChoose any valid option\n";
                break;
        }
    } while(option!=4);
}

int main(){
    int option;
    Node *tmp = NULL;
    AVL a;
    cout<<"\nAVL search tree implementation\n";
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\nSelect an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            tmp = new Node();
            cout<<"\nEnter the value: ";
            cin>>tmp->key;
            a.root = a.insert(a.root, tmp);
            cout<<"\nInserted\n";
            break;
        case 2:
            if(a.root==NULL){
                cout<<"\nNo elements to delete\n";
            }
            else{
                int k;
                cout<<"\nEnter the value to delete: ";
                cin>>k;
                a.root = a.deleteNode(a.root, k);
                cout<<"\nDeleted\n";
            }
            break;
        case 3:
            if(a.root==NULL){
                cout<<"\nNo elements to print\n";
            }
            else{
                print(a);
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