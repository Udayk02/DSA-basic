class Queue{
    int arr[100];
    int front = -1, rear = -1;
    public:
    void insert(int n);
    int delete_();
    bool isEmpty();
};

void Queue::insert(int n){
    if(front==-1){
        front=0;
    }
    rear++;
    arr[rear] = n;
}

int Queue::delete_(){
    if(front==0&&rear==0){
        int n = arr[front];
        front=rear=-1;
        return n;
    }
    int n = arr[front];
    for(int i=0;i<rear;i++){
        arr[i] = arr[i+1];
    }
    rear--;
    return n;
}

bool Queue::isEmpty(){
    if(front==-1||rear==-1){
        return true;
    }
    return false;
}