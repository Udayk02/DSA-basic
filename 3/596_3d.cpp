#include<iostream>
using namespace std;

void merge(int a[], int low, int mid, int high){
    int l = mid - low + 1;
    int r = high - mid;
    int L[l], R[r];
    for(int i=0;i<l;i++){
        L[i] = a[low+i];
    }
    for(int i=0;i<r;i++){
        R[i] = a[mid+1+i];
    }
    int i = 0, j = 0, k = low;
    while(i<l && j<r){
        if(L[i]<=R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<l){
        a[k] = L[i];
        i++;k++;
    }
    while(j<r){
        a[k] = R[j];
        j++;k++;
    }
}

void mergesort(int a[], int low, int high){
    if(low<high){
        int mid = (low + high)/2;

        mergesort(a, low, mid);
        mergesort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

void printArray(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int n;
    cout<<"\nMerge Sort\n\nEnter no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter the elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"\nUnsorted Array: ";
    printArray(a, n);
    mergesort(a, 0, n-1);
    cout<<"\nSorted Array: ";
    printArray(a, n);
}