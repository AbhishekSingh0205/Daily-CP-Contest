// //Problem Link : 
// #include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long int
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// // Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// #define pb push_back
// #define mp make_pair
// #define fl(i, a, b) for (int i = a; i < b; i++)
// #define vi vector<int>
// #define e1(a) int a; cin>>a;
// #define e2(a,b) int a,b; cin>>a>>b;
// #define e3(a,b,c) int a,b,c; cin>>a>>b>>c;
// #define __builtin_LIVU()  ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define av(arr,n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
// #define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
// #define es(s) string(s); cin >> (s);
// #define rz resize
// #define vvi vector<vector<int>>
// #define sz(s) s.size()
// #define mod 2
// #define ff first
// #define ss second
// #define inf 10e15
// #define all(x) (x).begin(), (x).end()
// #define pii pair<int, int>
// #define mii map<int,int>
// #define vl(n) cout << n << "\n"
// #define vs(n) cout << n << " "
// #define el cout<<"\n"
// #define rmin(a,b) (a=min((a),(b)))
// #define rmax(a,b) (a=max((a),(b)))
// #define UB upper_bound
// #define LB lower_bound
// #define vn(n) cout << n
// #define dsc greater<int>()
// #define ps(x,y)  fixed<<setprecision(y)<<x
// #define R return
// #define B break
// #define C continue
// #define YC cout<<"YES"<<"\n"
// #define YS cout<<"Yes"<<"\n"
// #define NC cout<<"NO"<<"\n"
// #define fv(a) for(auto v:(a))
// #define NS cout<<"No"<<"\n"
// #define lcm(a,b) (a/__gcd(a,b))*b
// #define pa(a) for(auto e:a)cout<<e<<" "
// const int N = 1e5 + 5;
// int dx[4] = { -1, 1, 0, 0};
// int dy[4] = {0, 0, -1, 1};
// int kx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
// int ky[8] = {0, 0, -1, 1, -1, 1, -1, 1};

// #ifndef ONLINE_JUDGE
// #define pra(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
// #define prm(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
// #define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
// template<class S, class T>ostream &operator<<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << "," << p.second << ")";}
// template<class T>ostream &operator<<(ostream &os, const vector<T> &p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
// template<class T>ostream &operator<<(ostream &os, const set<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
// template<class T>ostream &operator<<(ostream &os, const multiset<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
// template<class S, class T>ostream &operator<<(ostream &os, const map<S, T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
// template<class T>void dbs(string str, T t) {cerr << str << ":" << t << "\n";}
// template<class T, class...S>void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
// #else
// #define pr(...){}
// #define pra(a,n){}
// #define prm(mat,row,col){}
// #endif
// // Overloading for mod
// typedef long long ll;
// struct mint
// {
//     int val;
//     mint(int _val = 0)
//     {
//         val = _val % mod;
//     }
//     mint operator+(mint oth)
//     {
//         return val + oth.val;
//     }
//     mint operator*(mint oth)
//     {
//         return 1LL * val * oth.val;
//     }
//     mint operator-(mint oth)
//     {
//         return val - oth.val + mod;
//     }
//     void operator+=(mint oth)
//     {
//         val = (mint(val) + oth).val;
//     }
//     void operator-=(mint oth)
//     {
//         val = (mint(val) - oth).val;
//     }
//     void operator*=(mint oth)
//     {
//         val = (mint(val) * oth).val;
//     }
// };
// void getfact(int n,vi &getFct){
//     for(int i=2;i*i<=n;i++){
//         if(n%i==0){
//             getFct.pb(i);
//             while(n%i==0){
//                 n/=i;
//             }
//         }
//     }
//     if(n>1){
//         getFct.pb(n);
//     }
// }
// void solve()
// {
//     /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
//     // Finding the factors of a[i]/a[i-1]: These are use less factors, need to remove these factors from m/a[i]
//     // n(A U B U C U D U E) : Inclusion Exclusion.
//     // Now removing these factors -> We just need prime factors. So Prime Factors = log(a[i-1]/a[i]) || 10-11 prime factors.
//     // We can iterate over all prime factors of a[i-1]/a[i]. You will be able to this operatios just 30 times at max btw.
//     // See if we have any prime factor it will change to atmax 30times, as 2^32>10^9.
//     // We will just iterate over all prime factors in bit mask format around 30 times that's set.
//     // No n*2^30 time complexity.
//     e2(n,m);
//     av(a,n);
//     mint ans=1;
//     pr(n,m);
//     pr(a);
//     fl(i,1,n){
//         if(a[i-1]%a[i]){
//             pr("Here");
//             cout<<0<<endl;R;
//         }
//     }
//     fl(i,1,n){
//         int fctrs=a[i-1]/a[i];
//         if(a[i-1]==a[i]){
//             ans*=m/a[i];
//         }
//         else{
//             vector<int>getFct;
//             getfact(fctrs,getFct);
//             pr(getFct);
//             mint tmp=0;
//             int num=m/a[i];
//             tmp.val+=num;
//             for(int i=0;i<(1<<getFct.size());i++){
//                 int d=__builtin_popcount(i);
//                 int prdct=1;
//                 int id=0;
//                 int cst=i;
//                 while(cst){
//                     if(cst&1){
//                         prdct*=getFct[id];
//                     }
//                     id++;cst/=2;
//                 }
//                 pr(prdct);
//                 if(d%2){
//                     tmp-=num/prdct;
//                 }
//                 else{
//                     tmp+=num/prdct;
//                 }
//             }   
//             ans*=tmp.val;
//             pr(tmp.val);
//         }
//     }
//     cout<<ans.val<<endl;




// }
// int32_t main()
// {
//     __builtin_LIVU();
//     int t = 1;
//     cin >> t;
//     fl(i, 1, t + 1) {
//         solve();
//     }
//     return 0;
// }
// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 998244353;
const ld eps  = 1e-9 ;
const ll maxn = 1e5+1;
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

vector<ll> wheel(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        if(n % d == 0)
            factorization.push_back(d);
        while (n % d == 0) {
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        if(n % d == 0)
            factorization.push_back(d);
        while (n % d == 0) {
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

ll get_multiples(ll m, ll prev, ll num){
    vector<ll> factors = wheel(prev/num);

    ll totalMultiples = m/num;
    ll res = totalMultiples;

    ll facSize = factors.size();

    for(ll i=1 ; i<(1ll<<facSize) ; ++i){
        ll parity = __builtin_popcount(i)&1;
        ll currTerm = 1;
        for(ll j=0 ; j<facSize ; ++j){
            if( (i>>j)&1 ){
                currTerm *= factors[j];
            }
        }

        if(parity)
            res -= totalMultiples/currTerm;
        else
            res += totalMultiples/currTerm;
    }

    return res;
}

bool solve()
{
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n);

    for(ll i=0 ; i<n ; ++i) cin >> v[i];

    for(ll i=1 ; i<n ; ++i){
        if((v[i-1]%v[i])!=0)
            return false;
    }
    
    ll ans = 1;

    for(ll i=1 ; i<n ; ++i){
        if(v[i]==v[i-1]){
            ans *= (m/v[i]);
            ans %= mod;
        }
        else{
            ans *= get_multiples(m,v[i-1],v[i]);
            ans %= mod;
        }
    }

    cout << ans << endl;
    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }

    return 0;
} 