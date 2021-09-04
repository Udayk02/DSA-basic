#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char ch[100];
    char str[100];
    int i = 0, l = 0;
    cout << "Enter string : ";
    gets(ch);
    while(true)
    {
        if(ch[i+1] == '\0')
        {
            str[l] = ch[i];
            break;
        }
        if(ch[i] == ch[i+1])
        {
            i = i+2;
        }
        else
        {
            str[l] = ch[i];
            l = l+1;
            i = i+1;
        }
        if (ch[i] == '\0')
        {
            break;
        }
    }
    cout << "Resultant string : ";
    int k = 0;
    while(true){
        if(str[k+1]=='\0')  break;
        cout<<str[k];
        k++;
    }
}