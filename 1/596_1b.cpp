#include <iostream>

using namespace std;

void Towers_of_Hanoi(int n, char source[], char intermediate[], char destination[])
{
    if(n==1){
        cout<<"Move "<<n<<" from "<<source<<" to "<<destination<<"\n";
    }
    else{
        Towers_of_Hanoi(n-1, source, destination, intermediate);
        cout<<"Move "<<n<<" from "<<source<< " to "<<destination<<"\n";
        Towers_of_Hanoi(n-1, intermediate, source, destination);
    }
}

int main(){
    char source[] = "source";
    char intermediate[] = "intermediate";
    char destination[] = "destination";
    int n;
    cout<<"\nEnter number of Disk rows: ";
    cin>>n; cout<<"\n";
    Towers_of_Hanoi(n, source, intermediate, destination);
    return 1;
}
