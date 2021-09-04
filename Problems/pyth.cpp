#include<iostream>
using namespace std;

int gcd(int a, int b){
    static int i=1;
    if(i%a==0 && i%b==0){
        int r = i;
        i = 1;
        return (a*b)/r;
    }
    else{
        i++;
        return gcd(a,b);
    }
}

bool coprime_odd(int x, int y){
    if(gcd(x, y)==1&&(!((x%2!=0)&&(y%2!=0)))){
        return true;
    }
    return false;
}

void pyth(int limit){
    int a, b, c = 0, c1, x = 2;
    int count = 0;
    while(c<limit){
        for(int y = 1;y<x;++y){
            for(int k = 1;k<limit;++k){
                cout<<"k: "<<k<<"x: "<<x<<"y: "<<y<<"\n";
                if(coprime_odd(x, y)){
                    a = k*(x*x - y*y);
                    b = k*(2*x*y);
                    c = k*(x*x + y*y);
                }
                if(c>limit){
                    c = c1;
                    break;
                }
                c1 = c;
                cout<<"a: "<<a<<"b: "<<b<<"c: "<<c<<"\n";
                count++;
            }
        }
        x++;
    }
    cout<<"count: "<<count;
}

int main(){
    pyth(20);
}