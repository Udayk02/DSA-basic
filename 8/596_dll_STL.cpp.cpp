#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l1;
    int option;
    cout<<"Double linked list\n";
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print\n4. Exit\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
        {
            int opt;
            do{
                int n;
                cout<<"\nEnter value: ";
                cin>>n;
                cout<<"\n1. Beginning\n2. Position\n3. End\nCHoose an option: ";
                cin>>opt;
                switch (opt)
                {
                case 1:
                {
                    l1.push_front(n);
                    break;
                }
                case 2:
                {
                    int pos;
                    int count = 1;
                    cout<<"\nEnter position: ";
                    cin>>pos;
                    if(pos<=l1.size()){
                        auto i = l1.begin();
                        for(i;count!=pos;++i, ++count);
                        l1.insert(i, n);
                    }
                    else if(pos==l1.size()+1){
                        l1.push_back(n);
                    }
                    else{
                        cout<<"\nPosition not exists";
                    }
                    break;
                }
                case 3:
                {
                    l1.push_back(n);
                    break;
                }
                default:
                {
                    cout<<"\nValid option please";
                    break;
                }
                }
            } while(opt!=1&&opt!=2&&opt!=3);
            break;
        }
        case 2:
        {
            int opt;
            do{
                cout<<"\n1. Beginning\n2. Position\n3. End\nChoose an option: ";
                cin>>opt;
                switch(opt)
                {
                case 1:
                {
                    l1.erase(l1.begin());
                    break;
                }
                case 2:
                {
                    int pos1, count1 = 1;
                    cout<<"\nEnter position: ";
                    cin>>pos1;
                    if(pos1<=l1.size()){
                        auto i = l1.begin();
                        for(i;count1!=pos1;++i, ++count1);
                        l1.erase(i);
                    }
                    else if(pos1==l1.size()+1){
                        l1.erase(l1.end());
                    }
                    else{
                        cout<<"\nPosition not exists";
                    }
                    break;
                }
                case 3:
                {
                    l1.erase(l1.end());
                    break;
                }
                default:
                {
                    cout<<"\nValid option please";
                    break;
                }
                }
            } while(opt!=1&&opt!=2&&opt!=3);
            break;
        }
        case 3:
        {
            int opt;
            do{
                cout<<"\n1. Front\n2. Back\nChoose an option: ";
                cin>>opt;
                switch(opt)
                {
                case 1:
                {
                    for(auto i =l1.begin();i!=l1.end();++i){
                        cout<<*i<<" ";
                    }
                    break;
                }
                case 2:
                {
                    for(auto i =l1.rbegin();i!=l1.rend();++i){
                        cout<<*i<<" ";
                    }
                    break;
                }
                default:
                {
                    cout<<"\nValid option please";
                    break;
                }
                }
            } while(opt!=1&&opt!=2);
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            cout<<"\nValid option please";
            break;
        }
        }
    } while(option!=4);
}