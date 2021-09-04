//Evaluation of post fix expression
#include<iostream>

using namespace std;

class Stack
{
	int a[100],top=0;
	public:
	void push(int k);
	int pop();
};
void Stack :: push(int k)
{
	a[top]=k;
	top++;
}
int Stack :: pop()
{
	top--;
	return(a[top]);
}
int ifoperator(char ch)
{
	if(ch=='+' || ch=='-' || ch=='*' ||ch=='/')
	{
		return 1;
	}
	else
		return 0;
}
int oper(int a,int b,char ch)
{
	if (ch=='+')
		return a+b;
	else if (ch=='-')
		return a-b;
	else if(ch=='*')
		return a*b;
	else
		return a/b;
}
void  evalpf(char expr[],int n,int val[],char a[])
{
	Stack s;
	int res;
	for(int i=0;expr[i]!='\0';i++)
	{
		for(int j=0;j<n;j++)
		{
			if(expr[i]==a[j])
			{
				s.push(val[j]);
				break;
			}	
		}
		if(ifoperator(expr[i]))
		{
			int x=s.pop();
			int y=s.pop();
			char z=expr[i];
			
			res=oper(y,x,z);
			s.push(res);
		}
	}
	cout<<"The result is "<<res;
	
}
int main()
{
	int n;
	cout<<"Enter number of variables :";
	cin>>n;
	char expr[30],a[n];
	int val[n];
	
	cout<<"Enter expression in alphabets :";
	cin>>expr;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter variable "<<i+1<<" name :";
		cin>>a[i];
		cout<<"Enter "<<a[i]<<" value :";
		cin>>val[i];
	}
	evalpf(expr,n,val,a);
}
