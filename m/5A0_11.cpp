/*11. Write a program to perform the following operations using linked lists:
i) Insert an element into an AVL tree. ii) Delete an element from an AVL tree.*/

#include<iostream>
using namespace std;
class Node
{
    public:
    int key;
    Node *lst=NULL,*rst=NULL;
    int ht;
};
class rotate
{
    public:
    Node* lro(Node *);
    Node* rro(Node *);
};
class AVL : public rotate
{
    public:
    Node *root=NULL;
    
    Node *insert(Node*,Node*);
    Node *delet(Node*,int);
    Node *deletval(Node*,int);
    int bf(Node*);
    void inorder(Node*);
    int height(Node*);
    int max(Node *);
};

Node* rotate::rro(Node *root)
{
    Node* tmp;
    tmp=root->lst;
    root->lst = tmp->rst;
    tmp->rst=root;
    return tmp;
}
Node* rotate :: lro(Node *root)
{
    Node* tmp;
    tmp=root->rst;
    root->rst =tmp->lst;
    tmp->lst=root;
    return tmp;
}
Node* AVL::insert(Node* root,Node* tmp)
{
    if(root==NULL)
    {
        root=tmp;
    }
    else if(root->key>tmp->key)
    {
        root->lst=insert(root->lst,tmp);
        if(bf(root)>1 || bf(root)<-1)
        {
            if(root->lst->key>tmp->key)
            {
                root=rro(root);
                root->rst->ht=height(root->rst);
            }
            else
            {
                root->lst = lro(root->lst);
                root = rro(root);
                root->lst->ht = height(root->lst);
                root->rst->ht = height(root->rst);
            }
        }
        
    }
    else if(root->key<tmp->key)
    {
        root->rst=insert(root->rst,tmp);
        if(bf(root)>1 ||bf(root)<-1)
        {
            if(root->rst->key <tmp->key)
            {
                root=lro(root);
                root->lst->ht=height(root->lst);
            }
            else
            {
                root->rst = rro(root->rst);
                root = lro(root);
                root->lst->ht = height(root->lst);
                root->rst->ht = height(root->rst);
            }
        }
    }
    root->ht=height(root);
    return root;
}
Node* AVL::delet(Node* root,int val)
{
    if(root==NULL)
    {
        cout<<"No value to delete\n";
    }
    else if(root->key==val)
    {
        root=deletval(root,val);

    }
    else if(root->key>val)
    {
        root->lst=delet(root->lst,val);
        if(bf(root)>1 || bf(root)<-1)
        {
            if(bf(root->rst)==0||bf(root->rst)==-1)
            {
                root = lro(root);
                root->lst->ht = height(root->lst);
            }
            else if(bf(root->rst)==1)
            {
                root->rst = rro(root->rst);
                root = lro(root);
                root->lst->ht = height(root->lst);
                root->rst->ht = height(root->rst);
            }
        }
    }
    else if(root->key<val)
    {
        root->rst=delet(root->rst,val);
        if(bf(root)>1||bf(root)<-1)
        {
            if(bf(root->lst)==0||bf(root->lst)==1)
            {
                root = rro(root);
                root->rst->ht = height(root->rst);
            }
            else if(bf(root->rst)==-1)
            {
                root->lst = lro(root->lst);
                root = rro(root);
                root->lst->ht = height(root->lst);
                root->rst->ht = height(root->rst);
            }
        }
        
    }
    if(root!=NULL)
    {
        root->ht=height(root);
    }
    return root;
}

Node* AVL::deletval(Node *root,int val)
{
    if((root->lst==NULL) && (root->rst==NULL))
    {
        delete root;
        return NULL;
    }
    else if(root->lst==NULL && root->rst!=NULL)
    {
        return root->rst;
    }
    else if(root->rst==NULL && root->lst!=NULL)
    {
        return root->lst;
    }
    else
    {
        int k=max(root->lst);
        root->key=max(root->lst);
        root->lst=delet(root->lst,max(root->lst));
        return root;
    }
    
}
int AVL::max(Node* root)
{
    /*We traverse in rst bcoz max values will be in rst*/
    if(root->rst!=NULL)
    {
        root=root->rst;
    }
    return root->key;

}
int AVL :: bf(Node *root)
{
    //cout<<" Hi\n";
    int x=height(root->lst);
    //cout<<"MAhi\n";
    int y=height(root->rst);
    //cout<<"Reddy";
    return(x-y);
}
int AVL::height(Node* root)
{
    int ht=1,lht=1,rht=1;
    if(root==NULL)
    {
        return 0;
    }
    if((root->rst==NULL && root->lst==NULL))
    {
        //cout<<"01 ";
        ht=1;
    }
    else if(root->rst!=NULL && root->lst==NULL)
    {
        //cout<<"02";
        Node* tmp=root;
        while(tmp->rst!=NULL)
        {
            tmp=tmp->rst;
            rht++;
        }
        ht=rht;
    }
    else if(root->lst!=NULL && root->rst==NULL)
    {
        //cout<<"00";
        Node* tmp=root;
        while(tmp->lst!=NULL)
        {
            tmp=tmp->lst;
            lht++;
        }
        ht=lht;
    }
    else if(root->lst!=NULL && root->rst!=NULL)
    {
        height(root->lst)>=height(root->rst)?ht=1+height(root->lst):ht=1+height(root->rst);
    }
    return ht;
}
void AVL::inorder(Node* tmp)
{
    if(tmp!=NULL)
    {
        inorder(tmp->lst);
        cout<<tmp->key<<":"<<height(tmp)<<":"<<bf(tmp)<<" ";
        inorder(tmp->rst);
    }
}
int main()
{
    AVL a;
    
    cout<<"Implementation of a AVL tree\n";
    int op;
    while(true)
    {
        cout<<"1.Insert\t2.Delete\t3.Print\t4.Exit\n";
        cout<<"Select an option:";
        cin>>op;
        switch(op)
        {
            case 1:Node *tmp;
                    tmp=new Node();
                    cout<<"Enter a value :";
                    cin>>tmp->key;
                    tmp->lst=NULL;
                    tmp->rst=NULL;
                    a.root=a.insert(a.root,tmp);
                    break;
            case 2:int vals;
                    cout<<"Enter a value :";
                    cin>>vals;
                    a.root=a.delet(a.root,vals);
                    break;
            case 3:a.inorder(a.root);
                    cout<<endl;
                    break;
            case 4:exit(1);
            default:cout<<"Select proper statement ";

                    
        }
    }
    
}