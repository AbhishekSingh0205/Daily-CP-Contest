#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    stack<int>s;
    s.push(0);
    int res[n];
    res[0]=1;
    for(int i=1;i<n;i++){
        while(s.empty()==false && a[s.top()]<=a[i]){
            s.pop();
        }
        int tmp = s.empty()?-1:s.top();
        if(tmp==-1){
            tmp = i+1;
        }
        else{
            tmp = i-tmp;
        }
        res[i]=tmp;
        s.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}