#include<iostream>
#include<vector>

using namespace std;

int allocation(int B, vector<int> A){
    int max = 0;
    for(int i = 0;i<A.size();++i){
        if(max < A[i]){
            max = A[i];
        }
    }
    vector<int> count(max+1);
    for(int i = 0;i<A.size();++i){
        ++count[A[i]];
    }
    for(int i = 1;i<count.size();++i){
        count[i] += count[i-1];
    }
    vector<int> Af(A.size());
    for(int i = 0;i<A.size();++i){
        Af[count[A[i]]] = A[i];
        --count[A[i]];
    }
    int result = 0;
    for(int i = 0;i<Af.size();++i){
        if(Af[i] < B){
            ++result;
            B -= Af[i];
        }
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;++i){
        int count; int B;
        vector<int> A(count);
        for(int i = 0;i<count;++i){
            cin >> A[i];
        }
        arr[i] = allocation(B, A);
    }
    for(int i = 0;i<n;++i){
        cout<<"Case #"<<i+1<<": "<<arr[i]<<"\n";
    }
}