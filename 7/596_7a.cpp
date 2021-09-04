#include<iostream>
using namespace std;

class Queue{
    int arr[2][100];
    int front=-1, rear=-1;
    public:
    int max;
    void insert(int n, int p);
    void delete_();
    void print();
};

void Queue::insert(int n, int p){
    if(front==-1){
        front++; rear++;
        arr[0][front] = p;
        arr[1][front] = n;
        cout<<"Inserted";
        return;
    }
    rear++;
    int j = rear;
    if(rear==max){
        rear--;
        cout<<"Size exceeds";
        return;
    }
    else{
        for(int i=0;i<=rear;i++){
            if(i==rear){
                arr[0][rear] = p;
                arr[1][rear] = n;
                cout<<"Inserted";
                return;
            }
            if(arr[0][i]<p){
                for(j;j>i;j--){
                    arr[0][j] = arr[0][j-1];
                    arr[1][j] = arr[1][j-1];
                }   
                arr[0][i] = p; arr[1][i] = n;
                cout<<"Inserted";
                return;
            }
        }
    }
}

void Queue::print(){
    if(front==-1){
        cout<<"No element found";
    }
    else{
        for(int i=0;i<=rear;i++){
            cout<<arr[0][i]<<"\t";
        }
        cout<<"\n";
        for(int i=0;i<=rear;i++){
            cout<<arr[1][i]<<"\t";
        }
    }
}

void Queue::delete_(){
    if(rear==-1){
        cout<<"No elements to delete.";
    }
    else{
        if(rear==0){
            rear--; front--;
            cout<<"Deleted.";
            return;
        }
        for(int i=0;i<rear;i++){
            arr[0][i] = arr[0][i+1];
            arr[1][i] = arr[1][i+1];
        }
        rear--;
        cout<<"Deleted.";
    }
}

int main(){
    Queue q;
    int option;
    cout<<"\n\tPriority Queue Implementation\n\n";
    cout<<"Enter queue size: ";
    cin>>q.max;
    cout<<"Select an option:\n"; 
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\nChoose a option: ";
        cin>>option;
        switch (option)
        {
        case 1:
            int value, priority;
            cout<<"Enter a value: ";
            cin>>value;
            cout<<"Enter the priority: ";
            cin>>priority;
            q.insert(value, priority);
            break;
        case 2:
            q.delete_();
            break;
        case 3:
            q.print();
            break;
        case 4:
            cout<<"Exiting";
            break;
        default:
            cout<<"Choose a valid option.";
            break;
        }
    }while(option!=4);
}