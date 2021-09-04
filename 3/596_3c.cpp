#include<iostream>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[low];
    int left = low;
    int right = high+1;
    
    while(left<right){
        do{
            left++;
        }while(a[left]<pivot && left<=high);
        do{
            right--;
        }while(a[right]>pivot && right>=low);
        if(left<right){int temp = a[right]; a[right] = a[left]; a[left] = temp;}
    }
    a[low] = a[right]; a[right] = pivot;
    return right;
}

void quicksort(int a[], int low, int high){
    if(low<high){
        int mid = partition(a, low, high);

        quicksort(a, low, mid-1);
        quicksort(a, mid+1, high);
    }
}

int main(){
    int n;
    cout<<"\nQuick sort\n";
    cout<<"\nEnter no. of elements: ";
    cin>>n;
    int a[n];
    cout<<"\nEnter elements: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a, 0, n-1);
    cout<<"\nSorted array: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
