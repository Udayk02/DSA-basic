//Lower case string given. After single check of consecutive letters and after all possible checks.

#include<bits/stdc++.h>
using namespace std;

void func1(char *str, int size){
    char result[size];
    int k = 0;
    for(int i = 0;i<size;++i){
        if(str[i]==str[i+1]){
            i++;
        }
        else{
            result[k] = str[i];
            k++;
        }
    }
    for(int i = 0;i<k;++i){
        cout<<result[i];
    }
}

void func2(char *str, int size){
    char result[size];
    int k = 0;
    bool flag1;
    bool flag2 = false;
    do{
        flag1 = false;
        for(int i = 0;i<size;++i){
            if(str[i]==str[i+1]){
                i++;
                flag2 = true;
            }
            else{
                result[k] = str[i];
                k++;
            }
        }
        if(flag2){
            size = k;
            for(int i=0;i<k;++i){
                str[i] = result[i];
            }
            k = 0;
            flag1 = true;
            flag2 = false;
        }
    } while(flag1);
    if(k>0){
        for(int i = 0;i<k;++i){
            cout<<result[i];
        }
    }
    else{
        cout<<"empty";
    }
}

int main(){
    int size;
    cout<<"Enter size of the word: ";
    cin>>size;
    char str[size];
    cout<<"Enter the word: ";
    for(int i=0;i<size;++i){
        cin>>str[i];
    }
    cout<<"Word after a single check: ";
    func1(str, size);
    cout<<"\n";
    cout<<"Word after all possible checks: ";
    func2(str, size);
}