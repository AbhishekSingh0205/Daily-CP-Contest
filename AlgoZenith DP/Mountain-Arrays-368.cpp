#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define mod 1000000007
using namespace std;

int n,k;
int arr[1001];
int dp[1001][2][1001];
int rec(int level, int flag, int x){
    // base case and pruning
    if(level==n)    return 1;
    
    // cache
    if(dp[level][flag][x]!=-1){
        return dp[level][flag][x];
    }

    // transition
    int ans = 0;
    if(flag==0){    // arr[level-1] is the left, arr[x] is the right
        if(abs(arr[level]-arr[level-1]) <= k){
            ans = rec(level+1,0,x);
        }
        if(abs(arr[level]-arr[x]) <= k){
            ans = (ans + rec(level+1,1,level-1))%mod;
        }
    }else{      // arr[level-1] is the right, arr[x] is the left
        if(abs(arr[level]-arr[level-1]) <= k){
            ans = rec(level+1,1,x);
        }
        if(abs(arr[level]-arr[x]) <= k){
            ans = (ans + rec(level+1,0,level-1))%mod;
        }
    }
    // cout<<level<<" "<<x<<" "<<ans<<endl;
    // save and return
    return dp[level][flag][x] = ans;
}

void solve(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);
    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][0][j] = -1;
            dp[i][1][j] = -1;
        }
    }
    int ans = rec(1,0,0)-2;
    if(ans<0)   ans = 0;
    cout<<ans<<endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;    while(t--)
    solve();
    return 0;
}