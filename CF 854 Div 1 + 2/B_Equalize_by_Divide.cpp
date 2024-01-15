//Problem Link : 
#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_push_backds;
#define ff first
#define ss second
bool is1(vector<int>&a){
    int sm=a[0];bool is=true;
    for(int i=0;i<a.size();i++){
        if(sm!=a[i])is=false;
    }
    return is;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mnm=INT_MAX;
    for(int i=0;i<n;i++){
        if(a[i]<mnm){
            mnm=a[i];
        }
    }
    bool is=true;
    for(int i=0;i<n;i++){
        if(a[i]!=mnm) is=false;
    }
    if(mnm==1 && (!is)){
        cout<<-1<<endl;return;
    }
    if(is){
        cout<<0<<endl;return;
    }
    vector<pair<int,int>>res;
    while(is1(a)==false){
        mnm=INT_MAX;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(a[i]<mnm){
                mnm=a[i];
                ind=i;
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==a[ind]){
                continue;
            }
            int tmp=a[i]/a[ind];
            if(a[i]%a[ind]) tmp++;
            a[i]=tmp;
            res.push_back({i,ind});
        }
    }
    cout<<res.size()<<endl;
    for(auto v:res){
        cout<<v.ff+1<<" "<<v.ss+1<<endl;
    }

}
int32_t main()
{
    // __builtin_LIVU();
    int t = 1;
    cin >> t;
    for(int i=0;i<t;i++) {
        solve();
    }
    return 0;
}