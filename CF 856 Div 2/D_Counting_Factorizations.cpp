//Problem Link : 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
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
#define __builtin_LIVU()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define av(arr,n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
#define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
#define es(s) string(s); cin >> (s);
#define rz resize
#define vvi vector<vector<int>>
#define sz(s) s.size()
#define mod 998244353
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
const int N = 1e6 + 5;
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
int power(int a, int b, int m) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= (1ll);
    }
    return res;
}
int modInverse(int a,int m){
    return power(a,m-2,m);
}
#define MAXN 1000001
int spf[MAXN];
void seive(){
    for(int i=0;i<MAXN;i++){
        spf[i]=1;
    }
    spf[0]=0;spf[1]=0;
    for(int i=2;i<MAXN;i++){
        if(spf[i]==1){
            for(int j=i*i;j<MAXN;j+=i){
                spf[j]=0;
            }
        }
    }
}

void modVal(int &a){
    a%=mod;a+=mod;a%=mod;
}
int fact[N];
int inv[N];
int dp[4045][2023];
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*USE DOUBLE HASHING RATHER THAN SINGLE HASHING !!!!*/
    memset(dp,0,sizeof dp);
    e1(n);av(a,2*n);
    map<int,int>m;
    map<int,int>m2;
    fl(i,0,2*n){
        if(spf[a[i]]){
            m[a[i]]++;
        }
        else{
            m2[a[i]]++;
        }
    }
    if(m.size()<n){
        cout<<0<<endl;R;
    }
    fact[0]=1;
    inv[0]=modInverse(fact[0],mod);
    fl(i,1,N){
        fact[i]=i;fact[i]*=fact[i-1];
        modVal(fact[i]);
        inv[i]=modInverse(fact[i],mod);
        modVal(inv[i]);
    }
    // iterative DP.
    vector<pii>na;
    for(auto v:m) na.pb(v);
    int s=na.size();
    memset(dp,0,sizeof dp);
    dp[s-1][n-1]=inv[na[s-1].ss-1];
    dp[s-1][n]=inv[na[s-1].ss];
    pr(dp[na.size()-1][n-1],dp[na.size()-1][n]);
    for(int i=s-2;i>=0;i--){
        for(int j=n;j>=0;j--){
            dp[i][j]=inv[na[i].ss];// not taking ith prime.
            dp[i][j]*=dp[i+1][j];modVal(dp[i][j]);
            pr(dp[i][j]);
            if(j!=n){
                int tmp=inv[na[i].ss-1]; // taking ith prime
                tmp*=dp[i+1][j+1];modVal(tmp);
                dp[i][j]+=tmp;modVal(dp[i][j]);
            }
        }
    }
    int res2=fact[n];
    for(auto v:m2){
        res2*=inv[v.ss];modVal(res2);
    }
    res2*=dp[0][0];modVal(res2);
    cout<<res2<<endl;

}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    // cin >> t;
    seive();
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}