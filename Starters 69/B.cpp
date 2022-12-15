#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    string s;
    cin>>s;
    int c1=0;
    int c2=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='1'){
            c1++;
        }
        else{
            c2++;
        }
    }
    if(c1==0||c2==0){
        cout<<-1<<endl;return;
    }
    vector<int>fnd(2*n,0);
    vector<int>res;
    int cc=0;
    for(int i=0;i<2*n;i++){
        if(s[i]=='1'){
            cc++;
            res.push_back(i);
        }
        if(cc==n){
            break;
        }
    }
    if(cc<n){
        for(int i=0;i<2*n;i++){
            if(s[i]=='0'){
                res.push_back(i);
                cc++;
            }
            if(cc==n){
                break;
            }
        }
    }
    sort(res.begin(),res.end());
    for(int i=0;i<n;i++){
        cout<<res[i]+1<<" ";
    }
    cout<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}