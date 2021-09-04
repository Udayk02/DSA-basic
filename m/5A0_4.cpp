/* Hasing techniques
    Folding Methos
	Truncation method
	Modular method*/
#include<iostream>
#include<math.h>
using namespace std;
void folding()
{
	int size;
	cout<<"Enter size of hash table :";
	cin>>size;
	int key;
	cout<<"Enter the value to be hashed :";
	cin >> key;
	int numdigits=0,a=key,partsize,numparts;
	cout<<"Enter size of each part :";
	cin>>partsize;

	while(a!=0)
	{
		a=a/10;
		numdigits++;
	}
	if(numdigits%partsize==0)
		cout<<"We have "<<numdigits/partsize<<" parts\n";
	else
	{
		cout<<"We have "<<(numdigits/partsize)+(numdigits%partsize)<<" parts\n";
	}
	
	int count=0,tmp=0,sum=0,n=key,temp=0,digitscompleted=0;
	while(n!=0)
	{
		tmp=n%10;
		temp=temp+tmp*pow(10,count);
		count++;

		if(count==partsize)
		{
			cout<<"Part :"<<temp<<endl;
			digitscompleted=digitscompleted+count;
			count=0;
			sum=sum+temp;
			temp=0;
		}
		n=n/10;
	}
	if(digitscompleted<numdigits)
	{
		cout<<"Part :"<<temp<<endl;
		sum=sum+temp;
	}
	cout<<"Sum of parts :"<<sum<<endl;
	cout<<"The position of the hashed key "<<key<<" using folding method is "<<sum%size<<endl;

}
void truncation()
{
	int size;
	cout<<"Enter size of hash table :";
	cin>>size;
	int key;
	cout<<"Enter the value to be hashed :";
	cin >> key;
	int numdigits=0,n=key,m=key;
	while(n!=0)
	{
		n=n/10;
		numdigits++;
	}
	int a[numdigits];
	for(int i=numdigits;i>0;i--)
	{
		a[i]=m%10;
		m=m/10;
	}
	int pos1,pos2;
	cout<<"Enter position 1 :";
	cin>>pos1;
	cout<<"Enter position 2 :";
	cin>>pos2;
	if(pos2<pos1)
	{
		pos1=pos1+pos2;
		pos2=pos1-pos2;
		pos1=pos1-pos2;
	}
	if(pos1>numdigits||pos2>numdigits)
	{
		cout<<"Invalid positions";
	}
	int tmp=a[pos1]*10+a[pos2];
	cout<<"The position of hashed value "<<key<<" using truncation method is "<<tmp%size<<endl;
}
void modular()
{
	int size,key;
	cout<<"Enter size of hash table :";
	cin>>size;
	cout<<"Enter the value to be hashed :";
	cin>>key;
	cout<<"The position for hashed key "<<key<<" using modular method is "<<key%size<<endl;
}
int main()
{
	int n;
	while(true)
	{
		cout<<"Get the hash value \n";
		cout<<"1. By Folding method\t2. By Truncation method\t3. By Modular method\t4. Exit\n";
		cout<<"Enter an option :";
		cin>>n;
		switch(n)
		{
			case 1:folding();
					break;
			case 2:truncation();
					break;
			case 3:modular();
					break;
			case 4:exit(1);
			default:cout<<"Please select proper option";
		}
	}
	
}
