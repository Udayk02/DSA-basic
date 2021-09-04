#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
};

class cll{
    Node *front=NULL;
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
    void 
}