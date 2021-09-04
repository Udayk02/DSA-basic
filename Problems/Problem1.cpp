//Kung-fu Master maximum area rectangle problem

#include<iostream>
#include<stdlib.h>
using namespace std;

void sort(int k, int a[]){
    bool s = true;
    for(int i=0;i<k && s;i++){
        bool s = true;
        for(int j=0;j<(k-i-1);j++){
            if(a[j]>a[j+1]){
                int k = a[j+1];
                a[j+1] = a[j];
                a[j] = k;
                s = false;
            }
        }
        if(s){
            break;
        }
    }
}

void freq(int k, int a[], int n, int fre[]){
    int count=0;
    for(int i=0;i<k;i++){
        if(a[i]==n){
            count++;
        }
    }
    fre[n] = count;
}

int main(){
    int k, b[2] = {0, 0}, x=0;
    cout<<"Enter number of sticks: ";
    cin>>k;
    if(k<=3){ cout<<"Not possible"; exit(0); }
    int a[k];
    cout<<"Enter Stick lengths: ";
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    sort(k, a);
    int fre[a[k-1]+1], i, count;
    for(i=k-1;i>=0;i--){
        freq(k, a, a[i], fre);
        if(b[0]<a[i]&&fre[a[i]]>=4){
            b[0] = b[1] = a[i];
            break;
        }
        else if(fre[a[i]]>=2&&a[i]!=b[0]){
            b[x] = a[i];
            x++;
            if(x==2)    break;
        }
    }
    if(b[0]==0||b[1]==0){
        cout<<"Not possible";
    }
    else{
        cout<<"Area of the maximum area rectangle: "<<b[0]*b[1];
    }
    return 0;
}