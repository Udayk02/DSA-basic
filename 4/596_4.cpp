#include<iostream>
#include<math.h>

using namespace std;

void folding(int size){
    int parts, key, digits, count1=0;
    cout<<"\nEnter the size of each part: ";
    cin>>parts;
    cout<<"\nEnter the hash key: ";
    cin>>key;
    int n = key, count = 0;
    while(n!=0){
        n = n/10;
        count++;
    }   
    digits = count;
    if(digits%parts==0){
        cout<<"\nWe have "<<count/parts<<" parts."<<"\n";
    }
    else{
        cout<<"\nWe have "<<(count/parts)+(count%parts)<<"\n";
    }
    count = 0;
    int temp = 0, sum = 0;
    while(key!=0){
        int tmp = key%10;
        temp = temp + tmp*pow(10, count);
        count++;
        if(count==parts){
            cout<<"\nPart: "<<temp<<"\n";
            sum = sum + temp;
            temp = 0;
            count1 += count;
            count = 0;
        }
        key = key/10;
    }
    if(count1<digits){
        cout<<"\nPart: "<<temp<<"\n";
        sum = sum + temp;
    }
    cout<<"\nSum of the parts: "<<sum<<"\n";
    cout<<"\nThe position of the hash key by folding method: "<<sum%size<<"\n";
}

void truncation(int size){
    int digits = 0;
    int n = size-1;
    while(n!=0){
        n = n/10;
        digits++;
    }
    int p[digits];
    int key;
    cout<<"\nEnter the hash key: ";
    cin>>key;
    cout<<"\nEnter positions in the hash key to be taken\n";
    for(int i=0;i<digits;i++){
        cout<<"Position "<<i+1<<": ";
        cin>>p[i];
    }
    for(int i=0;i<digits;i++){
        if(p[i]==0){
            for(int j=i;j<digits-1;j++){
                p[j] = p[j+1];
            }
            digits--;
        }
    }
    int sum = 0, reverse = 0, count = 0, hash = key;
    while(key!=0){
        int k = key%10;
        reverse = reverse*10 + k;
        key = key/10;
        count++;
    }
    for(int i=0;i<digits;i++){
        if(p[i]>count){
            cout<<"\nInvalid positions, returning...\n";
            return;   
        }
    }
    for(int i=1;i<digits;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(p[j+1]<p[j])
			{
				int temp=p[j+1];
				p[j+1]=p[j];
				p[j]=temp;
			}
		}
	}
    count = 1;
    while(reverse!=0){
        int k = reverse%10;
        for(int i=0;i<p[i];i++){
            if(count==p[i]){
                sum = sum*10 + k;
            }
        }
        reverse = reverse/10;
        count++;
    }
    cout<<"\nThe position of the hash key by truncation method: "<<sum%size<<"\n";
}

void modular(int size){
    int key;
    cout<<"\nEnter the hash key: ";
    cin>>key;
    cout<<"\nThe position of the hash key by modular arithmetic method: "<<key%size<<"\n";
}

int main(){
    int size;
    int option;
    do{
        cout<<"\nEnter the Hash Table size: ";
        cin>>size;
        cout<<"\nHashing Techniques\n\n1. Folding method\n2. Truncation method\n3. Modular Arithmetic method\n4. Exit\n\nSelect an option: ";
        cin>>option;
        switch(option){
            case 1:
                folding(size);
                break;
            case 2:
                truncation(size);
                break;
            case 3:
                modular(size);
                break;
            case 4:
                cout<<"\n**EXITING**\n";
                break;
            default:
                cout<<"\nChoose a valid option";
                break;
        }
    } while(option!=4);
}