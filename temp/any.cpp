//Merge sort
#include<iostream>
using namespace std;

void merge(int a[],int l,int m,int h)
{
	int i,j,k;
	int n1=m,n2=h;
	
	
	//int l1[n1],l2[n2];
	//for(i=l;i<n1;i++)
	//	l1[i]=a[i];
	//for(j=m;j<n2;j++)
	//	l2[j]=a[j];
	
	
	int b[h+1];
	i=l;
	k=l;
	j=m+1;
	
	
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
	for(i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}
void mergesort(int a[],int l ,int h)
{
	if(l<h)
	{
		int m=(l)+ (h-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
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

