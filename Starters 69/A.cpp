#include<bits/stdc++.h>
using namespace std;
#define int long long int
void solve(){
    int n;cin>>n;
    int k;cin>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int brr[n];
    for(int i=0;i<n;i++){
        cin>>brr[i];
    }
    map<int,int>m;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])==m.end()){
            m[arr[i]]=brr[i];
        }
        else{
            m[arr[i]]=min(m[arr[i]],brr[i]);
        }
    }
    vector<int>res;
    for(auto v:m){
        res.push_back(v.second);
    }
    sort(res.begin(),res.end());
    if(res.size()<k){
        cout<<-1<<endl;return;
    }
    int i=0;
    int su=0;
    while(i<k){
        su+=res[i];
        i++;
    }
    cout<<su<<endl;
}
signed main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}