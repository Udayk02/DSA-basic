#include<iostream>
using namespace std;

class Hash{
    int key[100];
    int value[100];
    int top = 0;
    public:
    void hash(int n);
    void print();
};

void Hash::hash(int n){
    value[top] = n;
    int val = 1;
    int tens = 1;
    int d = 0, num = n;
    while(num>0){
        d++;
        num = num/10;
    }
    for(int i=0;i<d-1;i++){
        tens = tens*10;
    }
    for(int i=0;i<d;i++){
        int q = n/tens;
        val *= q;
        n = n%tens;
        tens = tens/10;
    }
    key[top] = val;
    top++;
}

void Hash::print(){
    cout<<"\nHash Table\n";
    cout<<"\nKey\tValue\n";
    for(int i=0;i<top;i++){
        cout<<key[i]<<"\t"<<value[i]<<"\n";
    }
}

int main(){
    Hash h;
    int option;
    do
    {
        cout<<"\n1. Enter\n2. Print\n3. Exit";
        cout<<"\nChoose an option: ";
        cin>>option;
        switch(option){
            case 1:
                int v;
                cout<<"\nEnter the value: ";
                cin>>v;
                h.hash(v);
                cout<<"\nValue added\n";
                break;
            case 2:
                h.print();
                break;
            case 3:
                cout<<"\n\nExiting\n\n";
                break;
            default:
                cout<<"\nInvalid option\n";
                break; 
        }
    } while (option!=3);
    return 1;    
}