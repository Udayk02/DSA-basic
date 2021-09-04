#include<iostream>
using namespace std;

class Queue{
    int arr[100];
    int front=-1, rear=-1;
    public:
    int max;
    void insert(int n);
    void delete_();
    void print();
};

void Queue::insert(int n){
    if(front==-1){
        arr[++rear] = n;
        front++;
        cout<<"Element inserted.";
    }
    else if(rear==max-1 && front>0){
        arr[0] = n;
        rear = 0;
        cout<<"Element inserted.";
    }
    else if((front==0&&rear==max-1)||(rear==front-1)){
        cout<<"No space available.";
    }
    else{
        arr[++rear] = n;
        cout<<"Element inserted.";
    }
}

void Queue::delete_(){
    if(front==-1){
        cout<<"\nNo elements to delete.";
        return;
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        if(front==max-1){
            front = 0;
            cout<<"\nDeleting in progress... Deleted.";
            return;
        }
        front++;
    }
    cout<<"\nDeleting in progress... Deleted.";
}

void Queue::print(){
    if(front==-1){
        cout<<"\nNo elements found.";
        return;
    }
    cout<<"\n\tCircular Queue\n";
    if(front<=rear){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=front;i<=max-1;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    Queue q;
    int option;
    cout<<"\n\tCircular Queue Implementation\n";
    cout<<"\n\nEnter queue size: ";
    cin>>q.max;
    cout<<"Select an option to perform: ";
    do
    {
        cout<<"\n\n1. Insert\n\n2. Delete\n\n3. Print\n\n4. Exit";
        cout<<"\n\nEnter an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            int value;
            cout<<"\nEnter your value: ";
            cin>>value;
            q.insert(value);
            break;
        case 2:
            q.delete_();
            break;
        case 3:
            q.print();
            break;
        case 4:
            cout<<"\n\nExiting\n\n";
            break;
        default:
            cout<<"\nChoose a valid option\n";
            break;
        }
    } while (option!=4);  
}