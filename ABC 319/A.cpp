//Problem Link : 
#include <bits/stdc++.h>
using namespace std;

int myfunc(int a,int b){
    int k=0;
    while(a-k*b>=b){
        ++k;
    }
    return a-k*b;
}
int main()
{
    char str[]="What is the size";
    printf("%d", sizeof(str));
    return 0;
}