//Doubly linked list implementation
#include<iostream>
using namespace std;
int num=0;
class node
{
	public:
	int key;
	node *left,*right;
};

class dll
{
	node *front=NULL,*rear=NULL;
	public :
	dll();
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
dll::dll()
{
	cout<<"\t\t\tDOUBLE LINKED LIST";
}
void dll::insertbeg(node *tmp)
{
	tmp->right=front;
	front->left=tmp;
	front=tmp;
	cout<<endl<<tmp->key<<" is inserted\n";
}

void dll::insertend(node *tmp)
{
	rear->right=tmp;
	tmp->left=rear;
	rear=tmp;
	cout<<endl<<tmp->key<<" is inserted\n";
	
}

void dll::insertpos(node *tmp)
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
			insertbeg(tmp);
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
				tmp2=tmp2->right;
				count++;
			}
			tmp->right=tmp2->right;
			tmp2->right->left=tmp;
			tmp2->right=tmp;
			tmp->left=tmp2;
			cout<<endl<<tmp->key<<" is inserted\n";
		}
	}

}
void dll::insertfirst(node *tmp)
{
	if(front==NULL && rear==NULL)
	{
		front=tmp;
		rear=tmp;
	}
}

void dll::deletebeg()
{
	node *tmp;
	tmp=front->right;
	front->right=NULL;
	tmp->left=NULL;
	delete front;
	front=tmp;
	cout<<"Element deleted\n";
    num--;
	
}
void dll::deleteend()
{

	node *tmp;
	tmp=rear->left;
	rear->left=NULL;
	tmp->right=NULL;
	delete rear;
	rear=tmp;
	cout<<"Element deleted\n";
    num--;

}

void dll::deletepos()
{

	int pos;
	cout<<endl<<"Enter position :";
	cin>>pos;
   	if (pos>num)
	{
		cout<<"Please select a valid position \n";
		deletepos();
	}
	else if (pos==num)
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
			tmp=tmp->right;
			count++;
		}
		tmp2=tmp->right;
		tmp->right=tmp2->right;
		tmp2->right->left=tmp;
		tmp2->right=NULL;
		tmp2->left=NULL;
		delete tmp2;
		cout<<"Element deleted\n";
        num--;
	}
}
void dll::deletefirst()
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

void dll ::print()
{
	int n;
	if(rear==NULL && front==NULL)
	{
		cout<<"No element exist ";
		return;
	}
	else
	{
		cout<<"1. Print from front\t2. Print from end\n";
		cout<<"Select an option :";
		cin>>n;
		if(n==1)
		{
			node *tmp;
			tmp=front;
			while(tmp->right!=NULL)
			{
				cout<<tmp->key<<" " ;
				tmp=tmp->right;
			}
			cout<<rear->key;
		}
		else if(n==2)
		{
			node *tmp;
			tmp=rear;
			while(tmp->left!=NULL)
			{
				cout<<tmp->key<<" " ;
				tmp=tmp->left;
			}
			cout<<front->key;
		}
		else
		{
			cout<<"Please select proper option\n";
			print();
		}
	}

}

int main()
{
	dll l;
	while(true)
	{
		cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\n";
		cout<<"select an option :";
		int n;
		cin>>n;
		switch(n)
		{
			case 1:num++;		//insert
				node *tmp;
				tmp=new node();
				cout<<"Enter a value :";
				cin>>tmp->key;
				tmp->right=NULL;
                tmp->left=NULL;
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
			default :cout<<"Please select proper option \n";
		}
	}
}