/*Write a program for the implementation of BFS and DFS for a given graph. */
#include<iostream>
using namespace std;
class Queue
{
    public:
	int a[100];
	int rear=-1,front=-1;
	
	void insert(int k);
	void print();
	int remove();
};
class graph
{
    public:
    int n;
    int m;
    Queue q;
    int count=0;
    int v[100];
    int status[100];
    int first;
    int adj[100][100];
    graph();
    void DFS();
    void BFS(int);
};
graph::graph()
{
    cout<<"Enter number of vertices:";
    cin>>n;
    cout<<"Enter values of vertices :";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        status[i]=0;
    }
    cout<<"Enter Adjacancy Marix :";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    cout<<"Enter First vertex:";
    cin>>first;
    q.insert(first);
}
void graph::BFS(int first)
{
    int i;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==first)
        {
            break;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(adj[i][j]==1&&status[j]==0)
        {
            q.insert(v[j]);
            status[i] = 1;
        }
    }
    cout<<"\n";
    for(int x=0;x<q.rear+1;x++){
        cout<<q.a[x]<<" ";
    }
    cout<<"\n";
    int y=q.remove();
    // count++;
    cout<<y<<" ";
    for(int k=0;k<n;k++)
    {
        if(status[k]==0)
        {
            m=0;
            cout<<"* ";
            break;
        }
        else
        {
            m=1;
        }
        
    }
    if(m==0)
    {
        first=q.a[q.front];
        cout<<"# ";
        BFS(first);
    }
    else{
        cout<<"& ";
        exit(0);
    }
    if(q.front==-1&&q.rear==-1){
        exit(0);
    }
    else{
        first = q.a[q.front];
        BFS(first);
    }
}

void Queue::insert(int k)
{
    if(front==-1&&rear==-1)
    {
        front++;
    }
    rear++;
    a[rear]=k;
}
int Queue::remove()
{
    if(front==0&&rear==0){
        int n = a[front];
        front = rear = -1;
        return n;
    }
    int x = a[front];
    for(int i=0;i<rear;i++){
        a[i] = a[i+1];
    }
    rear--;
    return x;
}
int main()
{   graph g;
    cout<<"1.BFS\t2.DFS\t3.Exit\n";
    int op;
    cout<<"Select an option:";
    cin>>op;
    while(true)
    {
        switch(op)
        {
            case 1:g.BFS(g.first);
                    break;
            case 2:/**/
            break;
            case 3:exit(1);
            default:cout<<"Select proper statement \n";

        }
    }

}