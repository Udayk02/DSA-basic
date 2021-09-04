//citcular queue

#include<iostream>

using namespace std;

class cq
{
	int Max,a[100];
	int front=-1,rear=-1;
	public:
	cq();
	void insert(int);
	void remove();
	void print();
};
cq :: cq()
{
	cout<<"Enter size of the circular queue :";
	cin>>Max;
}
void cq :: insert(int k)
{
	if((front==0&&rear==Max-1)||front==rear+1)
	{
		cout<<"No space in the queue";
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		a[rear]=k;
		cout<<endl<<a[rear]<<" Inserted ";
	}
	else if(front>0)
	{
		if(rear==Max-1)
		{
			rear=0;
			a[rear]=k;
			cout<<endl<<a[rear]<<" Inserted ";
		}
		else
		{
			a[++rear]=k;
			cout<<endl<<a[rear]<<" Inserted ";
		}
	}
	else
	{
		a[++rear]=k;
		cout<<endl<<a[rear]<<" Inserted ";
	}
			
}
void cq::remove()
{
	if(front==-1 && rear==-1)
	{
		cout<<"No element exists";
		
	}
	else if(front==Max-1 && rear!=Max-1)
	{
		front=0;
		cout<<"Element deleted successfully";
	}
	else if(front==rear)
	{
		rear=-1;
		front=-1;
		cout<<"Element deleted successfully";
	}
	else
	{
		front=front+1;
		cout<<"Element deleted successfully";
	}
	
}

void cq::print()
{
	if(front==-1 && rear==-1)
	{
		cout<<"No elements exist";
	}
	else if(rear<front)
	{
		for(int i=front;i<=Max-1;i++)
		{
			cout<<a[i]<<" ";
		}
		for(int i=0;i<=rear;i++)
		{
			cout<<a[i]<<" ";
		}
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
	cout<<"\t\tCircular Queue\n";
	cq q;
	while(true)
	{
		int k;
		cout<<"\n1 .Insert\n2 .Delete\n3 .Print all elements\n4 .Exit\n";
		cout<<"Select one option :";
		cin>>k;
		switch(k)
		{
			case 1: int n;
					cout<<endl<<"Enter one element :";
					cin>>n;
					q.insert(n);
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