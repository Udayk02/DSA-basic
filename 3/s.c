//Fibonacci search
#include<stdio.h>


int main()
{
	int n;
	printf("Enter number of elements :");
	scanf("%d",&n);
	int a[n],i,s;
	printf("Enter %d elemwnts :",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter search element :");
	scanf("%d",&s);
	int fm,fm1=0,fm2=1,offset=0;
	fm=fm1+fm2;
	while(fm<n)
	{
		fm2=fm1;
		fm1=fm;
		fm=fm1+fm2;
	}
	printf("%d\n",fm1);
	while(fm>1)
	{
		i==offset+fm2;
		if(a[i-1]>s)
		{
			fm=fm2;
			fm1=fm1-fm;
			fm2=fm-fm1;
			i=offset+fm2;
		}
		if(a[i-1]==s)
		{
			printf("Found at %d ",i-1);
			break;
		}
		if(a[i-1]<s)
		{
			offset=offset+fm2;
			fm=fm1;
			fm1=fm2;
			fm2=fm-fm1;
			i=offset+fm2;
			
		}
	}

	if(fm<1)
	printf("Not found!!!");
}