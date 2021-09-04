#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"\nInsertion sort\n\nEnter no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter "<<n<<" of elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[j+1]<a[j])
			{
				int temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
    cout<<"\nElements sorted: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 1;
}