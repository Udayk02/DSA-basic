//Quick sort
#include<iostream>

using namespace std;
int partition(int h,int a[],int l)
{
	int p=l,i=p,j=h-1;
	while(i<j)
	{
		while(a[i]<=a[p] && i<h)
		{
			i++;
		}
		while(a[j]>=a[p] && j>p)
		{
			j--;
		}
		if (i<j){
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
	int temp=a[p];
	a[p]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int h,int a[],int l)
{
	if(l<h)
	{
		int j;
		j=partition(h,a,l);
		quicksort(j,a,l);
		quicksort(h,a,j+1);
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n],i,j;
	cout<<"Enter "<<n<<" elements :";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(n,a,0);
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
}