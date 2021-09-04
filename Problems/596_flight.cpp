#include<iostream>

using namespace std;

int main(){
    int n, max=0, count;
    int p, q, r;
    cout<<"Enter N value: ";
    cin>>n;
    cout<<"Enter p, q, r values: ";
    cin>>p>>q>>r;
    for(int i=1;i<=n;++i){
        count = 0;
        if(i%p==0)  count++;
        if(i%q==0)  count++;
        if(i%r==0)  count++;
        if(count>1)    count = 0;
        max += count;
    }
    cout<<"\nMaximum flights: "<<max;
}