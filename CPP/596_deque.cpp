#include<iostream>
using namespace std;

class deque{
    int arr[100];
    int front = -1, rear = -1;
    public:
    int max;
    void insert_b(int n);
    void insert_e(int n);
    void delete_b();
    void delete_e();
    void print();
};

void deque::insert_b(int n){
    if(rear == max-1){
        cout<<"\nQueue size exceeds";
    }
    else{
        if(front==-1){
            front = rear = 0;
            arr[rear] = n;
            cout<<"\nInserted";
        }
        else
        {
            rear++;
            for(int i = rear;i>0;--i){
                arr[i] = arr[i-1]; 
            }
            arr[0] = n;
            cout<<"\nInserted";
        }
    }
}

void deque::insert_e(int n){
    if(rear == max-1){
        cout<<"\nQueue size exceeds";
    }
    else{
        if(front==-1){
            front = rear = 0;
        }
        rear++;
        arr[rear] = n;
        cout<<"\nInserted";
    }
}

void deque::delete_b(){
    if(rear==-1){
        cout<<"\nNo elements to delete";
    }
    else{
        if(rear==0){
            front = rear = -1;
            cout<<"\nDeleted";
        }
        else
        {
            for(int i=0;i<rear;++i){
                arr[i] = arr[i+1];
            }
            rear--;
            cout<<"\nDeleted";
        }
    }
}

void deque::delete_e(){
    if(rear==-1){
        cout<<"\nNo elements to delete";
    }
    else{
        if(rear==0){
            front = rear = -1;
            cout<<"\nDeleted";
        }
        else{
            rear--;
            cout<<"\nDeleted";
        }
    }
}

void deque::print(){
    if(front==-1){
        cout<<"\nNo element to print";
    }
    else{
        for(int i=front;i<=rear;++i){
            cout<<arr[i]<<" ";
        }
    }
}

int main(){
    deque q;
    int option;
    cout<<"\nDeque\n";
    cout<<"Enter your deque size: ";
    cin>>q.max;
    do{
        cout<<"\n\n1. Insert at the beginning\n2. Insert at the end\n3. Delete at the beginning\n4. Delete at the end\n5. Print\n6. Exit\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
        {
            int n;
            cout<<"\nEnter the value: ";
            cin>>n;
            q.insert_b(n);
            break;
        }
        case 2:
        { 
            int n;
            cout<<"\nEnter the value: ";
            cin>>n;
            q.insert_e(n);
            break;
        }
        case 3:
            q.delete_b();
            break;
        case 4:
            q.delete_e();
            break;
        case 5:
            q.print();
            break;
        case 6:
            break;
        default:
            cout<<"\nValid option please";
            break;
        }
    } while(option!=6);
}