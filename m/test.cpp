/*Write a program for the implementation of BFS and DFS for a given graph. */
#include<iostream>
using namespace std;
void func();
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
    int count=0;
    int v[100];
    Queue q;
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
    int m;
    
    for(i=0;i<n;i++)
    {
        if(v[i]==first)
        {
            status[i]=1;
            break;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(adj[i][j]==1)
        {
            if(status[j]!=1)
                q.insert(v[j]);
                status[j]=1;
                
        }
    }
    int y=q.remove();
    cout<<y<<" ";
    count++;
    for(int k=0;k<n;k++)
    {
        if(status[k]==0)
        {
            m=0;
            break;
        }
        else
        {
            m=1;
        }
        
    }
    /*if(m==0)
    {
        first=q.a[q.front];
        BFS(first);
    }*/
    if(count<=n)
    {
        first=q.a[q.front];
        BFS(first);
    }
    else 
        func();
        
    
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
    front++;
    return a[front-1];
}
graph g;
int main()
{   
    
    func();
}
void func()
    {
        cout<<"\n1.BFS\t2.DFS\t3.Exit\n";
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
