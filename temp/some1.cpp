//Merge sort
#include<iostream>
using namespace std;

void merge(int a[],int low,int mid,int high)
{
	int i=low;
    int n1=mid;
    int j=mid+1;
    int n2=high;
	int k=low;
	
	int b[high+1];
	
	while(i<=n1 && j<=n2)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
            k++;
		}
		else if(a[i]>a[j])
		{
			b[k]=a[j];
			j++;
            k++;
		}
        else if(a[i]==a[j]){
            b[k]=a[i];
            b[k+1]=a[j];
            i++;
            j++;
            k=k+2;
        }
		
	}
	while(i<=n1){
        b[k]=a[i];
        i++; k++;
    }
	while(j<=n2){
        b[k]=a[j];
        j++; k++;
    }
	for(i=low;i<=high;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int a[],int low ,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int n;
	cout<<"Enter number of elements :";
	cin>>n;
	int a[n];
	cout<<"Enter "<<n<<" elements :";
	for(int i=0;i<n;i++)
		cin>>a[i];
	mergesort(a,0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
}