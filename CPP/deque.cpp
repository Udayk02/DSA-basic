#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> q;
    int option;
    do{
        cout<<"\n1. Insert\n2. Delete\n3. Print4. Exit\nChoose an option: ";
        cin>>option;
        switch (option)
        {
        case 1:
        {
            int n;
            cout<<"\nEnter a value: ";
            cin>>n;
            int opt;
            do{
                cout<<"\n1. Insert at the beginning\n2. Insert at the end\nChoose an option: ";
                cin>>opt;
                switch (opt)
                {
                case 1:
                    q.push_front(n);
                    break;
                case 2:
                    q.push_back(n);
                    break;
                default:
                    cout<<"\nValid option please";
                    break;
                }
            } while(opt!=1&&opt!=2);
            break;
        }
        case 2:
        {
            int opt;
            do{
                cout<<"\n1. Delete at the beginning\n2. Delete at the end\nChoose an option: ";
                cin>>opt;
                switch (opt)
                {
                case 1:
                    q.pop_front();
                    break;
                case 2:
                    q.pop_back();
                    break;
                default:
                    cout<<"\nValid option please";
                    break;
                }
            } while(opt!=1&&opt!=2);
        }
        case 3:
        {
            cout<<"\n";
            for(auto i=q.begin();i!=q.end();++i){
                cout<<*i<<" ";
            }
            break;
        }
        case 4:
            break;
        default:
            cout<<"\nValid option please";
            break;
        }
    } while(option!=4);
}