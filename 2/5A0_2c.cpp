//Fibonacci search
#include<iostream>

using namespace std;
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n],i,s;
	cout<<"Enter "<<n<<" elements in sorted order :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter search element :";
	cin>>s;
	int fm,fm1=0,fm2=1,offset=-1;
	fm=fm1+fm2;
	while(fm<n)
	{
		fm2=fm1;
		fm1=fm;
		fm=fm1+fm2;
	}
	while(fm>=1)
	{
		i=(offset+fm2<n-1)?offset+fm2:(n-1);
		if(a[i]>s)
		{
			fm=fm2;
			fm1=fm1-fm;
			fm2=fm-fm1;
		}
		if(a[i]==s)
		{
			printf("Found at index %d ",i);
			break;
		}
		if(a[i]<s)
		{
			offset=offset+fm2;
			fm=fm1;
			fm1=fm2;
			fm2=fm-fm1;
		}
	}
	if(fm<1)
	cout<<"Not found!!!";
}