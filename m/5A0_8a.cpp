//Singly linked list implementation/
#include<iostream>
using namespace std;
int num=0;
class node
{
	public:
	int key;
	node *addr;
};

class ll
{
	node *front=NULL,*rear=NULL;
	public :
	ll();
	void insertbeg(node *);
	void insertend(node *);
	void insertpos(node *);
	void insertfirst(node *);
	
	void deletebeg();
	void deleteend();
	void deletepos();
	void deletefirst();
	
	void print();
};
ll::ll()
{
	cout<<"\t\t\tSINGLE LINKED LIST";
}
void ll::insertbeg(node *tmp)
{
	tmp->addr=front;
	front=tmp;
	cout<<endl<<tmp->key<<" is inserted\n";
}

void ll::insertend(node *tmp)
{
	rear->addr=tmp;
	rear=tmp;
	cout<<endl<<tmp->key<<" is inserted\n";
	
}

void ll::insertpos(node *tmp)
{
	int pos,count=1;
	cout<<"Enter position :";
	cin>>pos;
	if (pos>num)
	{
		cout<<"Please select a valid position \n";
		insertpos(tmp);
	}
	else
	{
		if(pos==1)
		{
			tmp->addr=front;
			front=tmp;
		}
		else if(pos==num)
		{
			insertend(tmp);
		}
		else
		{
			node *tmp2;
			tmp2=front;
			while(count<pos-1)
			{
				tmp2=tmp2->addr;
				count++;
			}
		
			tmp->addr=tmp2->addr;
			tmp2->addr=tmp;
			cout<<endl<<tmp->key<<" is inserted\n";
		}
	}
	
}
void ll::insertfirst(node *tmp)
{
	if(front==NULL && rear==NULL)
	{
		front=tmp;
		rear=tmp;
	}
}

void ll::deletebeg()
{

	node *tmp;
	tmp=front->addr;
	front->addr=NULL;
	delete front;
	front=tmp;
	cout<<"Element deleted\n";
    num--;

}
void ll::deleteend()
{
	node *tmp;
	tmp=front;
	while(tmp->addr!=rear)
	{
		tmp=tmp->addr;
	}
	tmp->addr=NULL;
	delete rear;
	rear=tmp;
	cout<<"Element deleted\n";
    num--;
	
}

void ll::deletepos()
{
	int pos;
	cout<<endl<<"Enter position :";
	cin>>pos;
   	if (pos>num)
	{
		cout<<"Please select a valid position \n";
		deletepos();
	}
	else if(pos==num)
	{
		deleteend();
	}
	else if (pos==1)
	{
		deletebeg();	
	}
	else
	{
		int count=1;
		node *tmp,*tmp2;
		tmp=front;
		while(count<pos-1)
		{
			tmp=tmp->addr;
			count++;
		}
		tmp2=tmp->addr;
		tmp->addr=tmp2->addr;
		tmp2->addr=NULL;
		delete tmp2;
		cout<<"Element deleted\n";
        num--;

	}
}
void ll::deletefirst()
{
	
	if(front==rear && front!=NULL)
	{
		delete rear;
		front=NULL;
		rear=NULL;
		cout<<"Element deleted\n";
		num--;
	}
	else if(front==NULL && rear==NULL)
	{
		cout<<"No element exists";
	}
}

void ll ::print()
{
	if(rear==NULL && front==NULL)
	{
		cout<<"No element exist \n";
		return;
	}
	node *tmp;
	tmp=front;
	while(tmp->addr!=NULL)
	{
		cout<<tmp->key<<" " ;
		tmp=tmp->addr;
	}
	cout<<rear->key;
}

int main()
{
	ll l;
	while(true)
	{
		cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\n";
		cout<<"select an option :";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:num++;		//insrt
				node *tmp;
				tmp=new node();
				cout<<"Enter a value :";
				cin>>tmp->key;
				tmp->addr=NULL;
			    if(num==1)
			    {
			    	l.insertfirst(tmp);
			    	cout<<tmp->key<<" inserted\n";
			    	break;
			    }
			    int n2;
				do
			    {
					cout<<"1. At begin\t2. At position\t3. At end\n";
					cout<<"Enter an option :";
					cin>>n2;
					switch(n2)
					{
						case 1:l.insertbeg(tmp);
							break;
						case 2 :l.insertpos(tmp);
							break;
						case 3 :l.insertend(tmp);
							break;
						default :cout<<"Please Select proper option \n";
					}
				}while(n2>3);
				break;
			case 2:		//delete
				if(num<=1)
				{
					l.deletefirst();
					break;
				}
				else{
				int n3;
				do{
				cout<<"1. At begin\t2. At position\t3. At end\n";
				cout<<"Enter an option :";
				cin>>n3;
				switch(n3)
				{
					case 1:l.deletebeg();
							break;
					case 2 :l.deletepos();
							break;
					case 3 :l.deleteend();
							break;
					default :cout<<"Please Select proper option \n";
				}
				}while(n3>3);
				}
				break;
			case 3:l.print();
					break;
			case 4:exit(1);
			default :cout<<"Please select proper option";
		}
	}
}