//Priority Queue

#include<iostream>
using namespace std;
class PQueue
{
	int a[100];
	int b[100];
	int pri=-1;
	int rear=-1,front=-1;
	int Max;
	public:

	void insert(int k,int p);
	void print();
	void remove();
	PQueue()
	{
		cout<<"Enter the size of queue :";
		cin>>Max;
	}
};
void PQueue :: insert(int k,int p)
{

	if(front==-1)
	{
		front++;
		rear++;
		a[front]=k;
		b[rear]=p;
		cout<<a[front]<<" inserted"<<endl;
	}
	else if(rear==Max-1)
	{
		cout<<"No space in the queue ";
	}
	else
	{
		a[++rear]=k;
		b[rear]=p;
		cout<<a[rear]<<" inserted"<<endl;
	}
	for(int i=front+1;i<=rear;i++)
	{
		for(int j=i-1;j>=front;j--)
		{
			if(b[j+1]>b[j])
			{
				//swapping keys
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
				
				//swapping priorities
				int temp2=b[j+1];
				b[j+1]=b[j];
				b[j]=temp2;
			}
		}
		
	}
}

void PQueue :: remove()
{
	if((front==-1 && rear==-1 )||(front >rear))
	{
		cout<<endl<<"No element exists";
	}
	else
	{
		front++;
		Max++;
		cout<<endl<<"Element deletion successful";
	}

}
void PQueue :: print()
{
	cout<<endl;
	if(front==-1||front>rear)
	{
		cout<<"No element found";
	}
	else
	{
		for(int i=front;i<=rear;i++)
		{
			cout<<a[i]<<" ";
		}
	}
}

int main()
{
	cout<<"\t\tPriority Queue\n";
	PQueue q;
	while(true)
	{
		int k;
		cout<<"\n1 .Insert\n2 .Delete\n3 .Print all elements\n4 .Exit\n";
		cout<<"Select one option :";
		cin>>k;
		switch(k)
		{
			case 1: int n,p;
					cout<<endl<<"Enter one element :";
					cin>>n;
					cout<<endl<<"Enter priority :";
					cin>>p;
					q.insert(n,p);
					break;
			case 2:q.remove();
					break;
			case 3:q.print();
					break;
			case 4:exit(1);
			default :cout<<"\nSelect correct option";
		}
	}
}