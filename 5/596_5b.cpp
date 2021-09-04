#include<iostream>
using namespace std;

class Queue{
    int arr[100];
    int front = -1, rear = -1;
    public:
    int max;
    void insert(int n);
    void delete_();
    void print();
};

void Queue::insert(int n){
    if(rear==max-1){
        cout<<"\nQueue size exceeds.\n";
    }
    else{
        if(front==-1){
            front=0;
        }
        rear++;
        arr[rear] = n;
        cout<<"It's Inserted";
    }
}

void Queue::delete_(){
    if(front==-1||rear==-1){
        cout<<"\nNo elements found\n";
    }
    else{
        if(front==0&&rear==0){
            front=rear=-1;
            cout<<"\nDeleted\n";
            return;
        }
        for(int i=0;i<rear;i++){
            arr[i] = arr[i+1];
        }
        rear--;
        cout<<"\nDeleted\n";
    }
}

void Queue::print(){
    if(front==-1||front==max){
        cout<<"\nThere's nothing to print here.\n";
    }
    else{
        cout<<"\n***Queue***\n\n";
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    Queue q;
    int option;
    cout<<"\nQueue Implementation\n\n";
    cout<<"Enter your queue size: ";
    cin>>q.max;
    cout<<"\nNow select an operation to be performed: ";
    do{
        cout<<"\n\n1. Insert\n\n2. Delete\n\n3. Print\n\n4. Exit\n\nEnter your option: ";
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
            cout<<"\nDeleting in progress...";
            q.delete_();
            break;
        case 3:
            q.print();
            break;
        case 4:
            cout<<"\n###Exiting###\n\n";
            break;
        default:
            cout<<"\nOh no! Unfortunately there's no such kinda option. Please select one of the following options: ";
            break;
        }
    }while(option!=4);
}