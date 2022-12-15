//Problem Link : 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define ll int
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
// #define mod 998244353
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
long long moduloMultiplication(long long a, long long b,
                               long long mod)
{
  
    // Initialize result
    long long res = 0; 
  
    // Update a if it is more than
    // or equal to mod
    a %= mod;
  
    while (b) {
  
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;
  
        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;
        b >>= 1; // b = b / 2
    }
    return res;
}
  
// C++ function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b,
                          ll* x,
                          ll* y);
  
// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't exists
ll modInverse(ll b, ll m)
{
  
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);
  
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
  
    // m is added to handle negative x
    return (x % m + m) % m;
}
  
// C function for extended Euclidean Algorithm (used to
// find modular inverse.
ll gcdExtended(ll a, ll b,
                          ll* x,
                          ll* y)
{
  
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
  
    // To store results of recursive call
    ll x1, y1; 
  
    ll gcd = gcdExtended(b % a, a, &x1, &y1);
  
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
  
// Function to compute a/b under modulo m
ll modDivide(ll a, ll b,
                        ll m)
{
  
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
        // cout << "Division not defined";
        return 0;
    else
        return (inv * a) % m;
}
  
// Function to calculate nCr % p
int nCr(int n, int r, int p)
{
  
    // Edge Case which is not possible
    if (r > n)
        return 0;
  
    // Optimization for the cases when r is large
    if (r > n - r)
        r = n - r;
  
    // x stores the current result at
    ll x = 1; 
    
    // each iteration
    // Initialized to 1 as nC0 is always 1.
    for (int i = 1; i <= r; i++) {
  
        // Formula derived for calculating result is
        // C(n,r-1)*(n-r+1)/r
        // Function calculates x*(n-i+1) % p.
        x = moduloMultiplication(x, (n + 1 - i), p);
        
        // Function calculates x/i % p.
        x = modDivide(x, i, p);
    }
    return x;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    int lft=0;
    e1(n);es(s);
    int fix0=0,fix1=0;
    int ans=1;
    int mod=998244353;
    if(s[0]=='0'){
        fix0++;
    }    
    else{
        fix1++;
    }
    // pr(fix1,fix0);
    int l=1;
    int prev=1;
    for(int i=1;i<n;i++){
        l++;
        lft++;
        // pr(lft);
        if(s[i]=='1'){
            fix1++;
            // pr("if1");
            // pr(fix0,fix1,l,lft);
            if(fix1<l){
                int req=l-fix1;
                // pr(req);
                int nans=nCr(lft,req,mod);
                prev=nans;
                ans+=prev;
                fix1+=(req);
                lft=lft-req;
            }
            else{
                // pr("noreq");
                // lft++;
                prev*=2;
                ans+=prev;
            }
        }
        else{
            fix0++;
            // pr("if0");
            // pr(fix0,fix1,l);
            if(fix0<l){
                int req=l-fix0;
                // pr(req);
                int nans=nCr(lft,req,mod);
                prev=nans;
                ans+=prev;
                fix0+=(req);
                lft=lft-req;
            }
            else{
                // pr("noreq");
                // lft++;
                prev*=2;
                ans+=prev;
            }
        }
        // pr(fix0,fix1);
        // pr(lft);
        // pr(prev);
        prev%=mod;
        prev+=mod;
        prev%=mod;
        ans%=mod;
        ans+=mod;
        ans%=mod;
    }
    ans%=mod;
    ans+=mod;
    ans%=mod;
    cout<<ans<<endl;


}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}