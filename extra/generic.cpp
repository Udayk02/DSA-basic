#include<iostream>

using namespace std;

template<class L>
struct node {
    node<L>* next;
    L data;
};

template<class L>
class LinkedList {
public:
    node<L>* head;
    node<L>* rear;
    LinkedList<L>() {
        head = NULL;
        rear = NULL;
    }   

    void add(L data) {
        if(!head){
            head = new node<L>;
            head -> data = data;
            head -> next = NULL;
            rear = head;
        }
        else if(head == rear) {
            rear = new node<L>;
            rear -> data = data;
            rear -> next = NULL;
            head -> next = rear;
        }
        else{
            node<L>* temp = new node<L>;
            temp -> data = data;
            temp -> next = NULL;
            rear -> next = temp;
            rear = temp;
        }
    }

    L get(int index) {
        if(index==0){
            return this -> head -> data;
        }
        else{
            node<L>* temp = this -> head;
            for(int i = 0;i < index;++i){
                temp = temp->next;
            }
            return temp -> data;
        }
    }
};

int main(){
    LinkedList<string> str;
    str.add("hello");
    cout<<str.get(0)<<" ";
    LinkedList<int> Int;
    Int.add(5);
    cout<<Int.get(0);
}