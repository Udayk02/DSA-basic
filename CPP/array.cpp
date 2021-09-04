#include<iostream>
#include<array>

using namespace std;

int main(){
    array<int, 5> arr1 = {10, 20, 30, 40, 90};
    array<int, 1>::iterator i;
    for(i=arr1.begin(); i!=arr1.end();i++){
        cout<< *i <<"\n";
    }
    cout<<arr1._M_elems;
    
}