//Problem Link : 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define ll long long 
#define lli long long
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
#define modi 998244353 
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



// Returns (val1 * val2) % mod
ll moduloMultiplication(ll val1, ll val2,ll mod)
{

    // Initialize the result
    ll ans = 0;

    // Update val1 if it is greater than or equal to mod
    val1 %= mod;

    while (val2) {

        // If val2 is odd, add a with result
        if (val2 & 1)
            ans = (ans + val1) % mod;

        // Here we assume that doing 2*val1 doesn't cause overflow
        val1 = (2 * val1) % mod;
        val2 = val2/2;
    }
    return ans;
}

// C++ function for extended Euclidean Algorithm
lli gcdExtended(lli val1, lli val2,lli* xx,lli* yy);

// Function to find modulo inverse of val2 if inverse does not exist it returns -1
lli modInverse(lli val2, lli mod)
{

    // used in extended GCD algorithm
    lli xx, yy; 
    lli g = gcdExtended(val2, mod, &xx, &yy);

    // Return -1 if val2 and mod are not co-prime
    if (g != 1)return -1;

    // mod is added to handle negative xx
    return (xx % mod + mod) % mod;
}

// Function for extended Euclidean Algorithm to find modular inverse.
lli gcdExtended(lli val1, lli val2,lli* xx,lli* yy)
{

    // Base Case
    if (val1 == 0) {
        *xx = 0, *yy = 1;
        return val2;
    }

    // To store results of recursive call
    lli x1, y1;

    lli gcd = gcdExtended(val2 % val1, val1, &x1, &y1);

    // Update xx and yy using results of recursive call
    *xx = y1 - (val2 / val1) * x1;
    *yy = x1;
    return gcd;
}

// Function to compute val1/val2 under modlo mod
lli modDivide(lli val1, lli val2,lli mod)
{

    val1 = val1 % mod;
    lli inv = modInverse(val2, mod);
    if (inv == -1)
        // Divison not defined
        return 0;
    else
        return (inv * val1) % mod;
}

// Function to calculate nCr % p
int computencr(int n, int r, int x)
{

    // Base case this case is not possible
    if (r > n)
        return 0;

    // For larger r optimization need to be done
    if (r > n - r)
        r = n - r;

    // ans stores the current result 
    lli ans = 1;

    for (int i = 1; i <= r; i++) {

        /*
             Derived formula for calculating the result is
             C(n,r-1)*(n-r+1)/r
             this Function calculates ans*(n-i+1) % x.
        */

        ans = moduloMultiplication(ans, (n + 1 - i), x);
    
        // Function calculates ans/i % x
        ans = modDivide(ans, i, x);
    }
    return ans;
}
int dp[61][2];
int rec(int i,int t,int n){
    if(i==n-1){
        if(t==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(dp[i][t]!=-1){
        return dp[i][t];
    }
    int ans=0;
    if(t==1){
        // Abhi jeetado
        ans=computencr(n-i,(n/2)-((i+1)/2),modi);
        // Make it for this case
        ans+=rec(i+2,0,n);
        ans%=modi;
    }
    else{
        // Phle to loose nhi krna hai.
        ans=rec(i+2,1,n);
        int ttl=(i/2)+2;
        int rem=(n/2)-ttl;
        ans+=computencr(n-(i+1),rem,modi);
        ans%=modi;
    }
    ans%=modi;
    ans+=modi;
    ans%=modi;
    return dp[i][t]=ans;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    int n;cin>>n;
    memset(dp,-1,sizeof dp);
    // t=1 ->alex ; t=0 ->bern
    int ttl=computencr(n,n/2,modi)%modi;
    int win=rec(1,1,n);
    int draw=1;
    cout<<((win%modi)+modi)%modi<<" "<<(((ttl-1-win)%modi)+modi)%modi<<" "<<1<<endl;    



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