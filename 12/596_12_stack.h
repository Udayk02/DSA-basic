class Stack{
    int a[100];
    int top = 0;
    public:
    void push(int);
    int pop();
    bool isEmpty();
};

void Stack::push(int n){
    a[top] = n;
    top++;
}

int Stack::pop(){
    top--;
    return a[top];
}

bool Stack::isEmpty(){
    if(top==0){
        return true;
    }
    return false;
}