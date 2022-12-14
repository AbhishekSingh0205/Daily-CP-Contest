/*
    We can calculate minimum length greedily.
    Now calculating the number of ways using DP.
*/
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// #define int long long int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define pb push_back
#define mp make_pair
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define e1(a) int a; cin>>a;
#define e2(a,b) int a,b; cin>>a>>b;
#define e3(a,b,c) int a,b,c; cin>>a>>b>>c;
#define av(arr,n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
#define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
#define es(s) string(s); cin >> (s);
#define rz resize
#define vvi vector<vector<int>>
#define sz(s) s.size()
#define mod 1000000007
#define ff first
#define ss second
#define inf 10e15
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define mii map<int,int>
#define vl(n) cout << n << "\n"
#define vs(n) cout << n << " "
#define el cout<<"\n"
#define rmin(a,b) (a=min((a),(b)))
#define rmax(a,b) (a=max((a),(b)))
#define UB upper_bound
#define LB lower_bound
#define vn(n) cout << n
#define dsc greater<int>()
#define ps(x,y)  fixed<<setprecision(y)<<x
#define R return
#define B break
#define C continue
#define YC cout<<"YES"<<"\n"
#define YS cout<<"Yes"<<"\n"
#define NC cout<<"NO"<<"\n"
#define fv(a) for(auto v:(a))
#define NS cout<<"No"<<"\n"
#define lcm(a,b) (a/__gcd(a,b))*b
#define pa(a) for(auto e:a)cout<<e<<" "
const int N = 1e5 + 5;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int kx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
int ky[8] = {0, 0, -1, 1, -1, 1, -1, 1};

#ifndef ONLINE_JUDGE
#define pra(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define prm(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S, class T>ostream &operator<<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << "," << p.second << ")";}
template<class T>ostream &operator<<(ostream &os, const vector<T> &p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const set<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const multiset<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class S, class T>ostream &operator<<(ostream &os, const map<S, T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>void dbs(string str, T t) {cerr << str << ":" << t << "\n";}
template<class T, class...S>void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
#else
#define pr(...){}
#define pra(a,n){}
#define prm(mat,row,col){}
#endif
string s,t;
int rec(int i,int prevTkn,int j,vector<pii>&a,vector<vvi>&dp){
    // Base case: if(j==0) that is length is zero then no substring of T should be remaining that from i to a.size() there should be no a[i].ff>prevTkn
    // if there is so then we will return 0.
    // else we will return 1
    // pr(i,prevTkn,j);
    // pr(a);
    if(i>=a.size() && j){
        return 0;
    }
    if(j<0){
        return 0;
    }
    if(j==0){
        for(int k=i;k<a.size();k++){
            if(a[k].ff>prevTkn){
                return 0;
            }
        }
        return 1;
    }
    if(dp[i][prevTkn][j]!=-1){
        return dp[i][prevTkn][j];
    }
    // basically ith node le skta hu, ya ith ke last wala jaha pe jaa rha hai wha.
    // Let's say a[j].ff<=a[i].ss then let's I took jth node
    // then my recursive relation would be 
    // ans += rec(j+1,a[j].ss,j-1,a,dp) [for each j such that a[j].ff<=a[i].ss]
    int ans=0;
    if(a[i].ff<=prevTkn){
        ans=rec(i+1,prevTkn,j,a,dp);
        ans%=mod;
    }
    else{
        for(int k=i;k<a.size();k++){
            if(a[k].ff<=a[i].ss){
                ans+=rec(k+1,a[k].ss,j-1,a,dp);
                ans%=mod;
            }
        }
    }
    return dp[i][prevTkn][j]=ans%mod;
}
void solve()
{
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<pii>res;
    for(int i=0;i<n;i++){
        if(s[i]==t[0]){
            bool is=false;
            for(int j=0;j<m;j++){
                if(s[i+j]!=t[j]){
                    is=true;
                    B;
                }
            }
            if(!is) res.pb({i,i+m-1});
        }
    }
    int cnt=0;
    int l=res.size();
    pr(res);
    int i=0;
    int prevTkn=-1;
    // Calculating the minimum length
    while(i<l){
        if(prevTkn>=res[i].ff){
            i++;C;
        }
        if(i+1<l){
            int currL=res[i].ss;
            while(i+1<l && res[i+1].ff<=currL){
                i++;
            }
            cnt++;
            prevTkn=res[i].ss;
            i++;
            C;
        }
        prevTkn=res[i].ss;
        cnt++;i++;
    }
    for(int i=0;i<res.size();i++){
        res[i].ff++;res[i].ss++;
    }
    cout<<cnt<<" ";
    pr("Worked Here1");
    vector<vector<vi>>dp(res.size()+1,vvi(502,vi(cnt+1,-1)));
    pr("W2");
    int ans=rec(0,0,cnt,res,dp);
    ans%=mod;
    cout<<ans<<endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}