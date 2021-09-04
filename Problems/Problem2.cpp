//Almost equally skilled Horses

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

int main(){
    int k;
    cout<<"Enter number of horses: ";
    cin>>k;
    if(k<2){ cout<<"More horses required"; exit(0); }
    int a[k];
    cout<<"Enter skills of the horses: ";
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    sort(k, a);
    int diff[k-1];
    for(int i=0;i<k-1;i++){
        diff[i] = a[i]-a[i+1]>=0?a[i]-a[i+1]:a[i+1]-a[i];
    }
    int min = diff[0], x=0;
    for(int i=0;i<k-1;i++){
        if(min>diff[i]){
            min = diff[i];
            x = i;
        }
    }
    cout<<"\nAlmost equally skilled horses\nSkill-1: "<<a[x]<<" Skill-2: "<<a[x+1];
}
