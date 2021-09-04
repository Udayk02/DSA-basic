#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<long int> a1;

    for(int j = 0; j<100; j++){
        a1.push_back(j);
        cout<<a1.capacity()<<" "<<a1.size()<<" "<<a1.at(j)<<"\n";
    }
}