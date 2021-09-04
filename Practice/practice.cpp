//Circular queue implementation

#include<iostream>
using namespace std;

class circularQueue{
    int front = -1;
    int rear = -1;
    int arr[100];
    int max;
    public:
    circularQueue();
    int insert(int);
    void delete_();
    void print();
};

circularQueue::circularQueue(){
    cout<<"\nEnter the size of the queue: ";
    cin>>max;
}

int circularQueue::insert(int x){
    if(front==-1){
        arr[0] = x;
        front++; rear++;
    }
    else if((front==0&&rear==max-1)||(rear==front-1)){
        cout<<"\nQueue size exceeds";
        return 0;
    }
    else if(rear==max-1&&front>0){
        rear = 0;
        arr[0] = x;
    }
    else{
        arr[++rear] = x;
    }
    return 1;
}

void circularQueue::delete_(){
    if(front==-1){
        cout<<"\nNo elements to delete";
    }
    else if(front==rear){
        front = rear = -1;
    }
    else if(front==max-1){
        front = 0;
    }
    else{
        front++;
    }
}

void circularQueue::print(){
    cout<<"\nCircular Queue: ";
    if(front==-1){
        cout<<"Empty";
    }
    else if(front <= rear){
        for(int i = front;i<=rear;++i){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i = front;i<max;++i){
            cout<<arr[i]<<" ";
        }
        for(int i = 0;i<=rear;++i){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    circularQueue q;
    int option;
    do{
        cout<<"\nCircular Queue Implementation\n1. Insert\n2. Delete\n3. Print\n4. Exit\nChoose an option: ";
        cin>>option;
        switch(option){
            case 1:{
                int value;
                cout<<"\nEnter value: ";
                cin>>value;
                int flag = q.insert(value);
                if(flag==1){
                    cout<<"\nInserted";
                }
                break;
            }
            case 2:
                q.delete_();
                break;
            case 3:
                q.print();
                break;
            case 4:
                break;
            default:
                cout<<"\nChoose a valid option";
                break;
        }
    } while(option!=4);
}