#include<stdio.h>
#include<string.h>

void func()
{
    int a;
    memset(&a, 0, 100); // Corrupt SFR values stored in stack frame
}
int main()
{
    func();
    return 0;
}