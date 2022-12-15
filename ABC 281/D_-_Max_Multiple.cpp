#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize(3, "Ofast", "inline")
 
#include<bits/stdc++.h> 
using namespace std;
using namespace chrono;
#define endl "\n"
 
#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif
 
#define ull long long unsigned
#define int long long int
#define double long double
#define pb push_back
#define mk make_pair
#define ppb pop_back
#define pf  push_front
#define ppf  pop_front
#define all(x) (x).begin(),(x).end()
#define ub upper_bound
#define lb lower_bound
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define sz(x)  (int)((x).size())
#define fr first
#define sc second
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mem1(a) memset(a,-1,sizeof(a))
#define mem0(a) memset(a,0,sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
 
int const N=2*1e5+10;
int const INF=1e17;
int mod=1e9+7;
int mod1=998244353;
//const int INF=1e15;
// int dx[]={1,1,-1,-1,0,0,-1,1};
// int dy[]={-1,1,-1,1,-1,1,0,0};
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
string S="LRUD";

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
  

  
 
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
int n,k,d;
vector<int>arr;
int dp[101][101][101];

int recur(int i, int j, int rem){
  if(j==k){
    if(rem%d==0)return 0;
    return -1*INF;
  }
  if(i>=n)return -1*INF;
  
  if(dp[i][j][rem]!=-1)
    return dp[i][j][rem];
  
  return dp[i][j][rem]=max(recur(i+1,j,rem),
    arr[i]+recur(i+1,j+1,(rem+arr[i]%d)%d));
}
 
void solve(){
  mem1(dp);
 cin>>n>>k>>d;
 arr.resize(n);
 rep(i,0,n)cin>>arr[i];
 if(recur(0,0,0)<0)cout<<"-1";
 else cout<<recur(0,0,0);
 
 return;
 
}
 
 
 
signed main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif 
  
  
    fastio();
    auto start1 = high_resolution_clock::now();
    int t=1;
    //cin>>t;
    // precompute();
    
    //fill_dp();
   // int ct=0;
    while(t--){
      //ct++;
      
      solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    #ifndef ONLINE_JUDGE
    cout << "Time: " << duration . count() / 1000 <<"ms"<<endl;
    #endif
  
  return 0;
}