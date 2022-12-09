//Problem Link : https://www.learning.algozenith.com/problems/Kadane-Twist-896
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
#define mod 1000000007
#define ff first
#define ss second
#define inf 1e18
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
struct quad{
    int ts,left_ms,right_ms,ms;
};
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e2(n,m);
    vector<int>arr[n];
    fl(i,0,n){
        e1(x);
        for(int j=0;j<x;j++){
            e1(tmp);
            arr[i].pb(tmp);
        }   
    }
    quad a[n];
    for(int i=0;i<n;i++){
        int ts=0;
        int left_ms=-inf,t1=0;
        int right_ms=-inf,t2=0;
        int cs=0,ms=-inf;
        for(int j=0;j<arr[i].size();j++){
            ts+=arr[i][j];
        }
        for(int j=0;j<arr[i].size();j++){
            t1+=arr[i][j];
            left_ms=max(t1,left_ms);
        }
        for(int j=arr[i].size()-1;j>=0;j--){
            t2+=arr[i][j];
            right_ms=max(right_ms,t2);
        }
        for(int j=0;j<arr[i].size();j++){
            cs+=arr[i][j];
            ms=max(ms,cs);
            if(cs<0){
                cs=0;
            }
        }
        a[i].ts=ts;
        a[i].left_ms=left_ms;
        a[i].right_ms=right_ms;
        a[i].ms=ms;
    }
    // for(int i=0;i<n;i++){
    //     cout<<a[i].left_ms<<" "<<a[i].right_ms<<" "<<a[i].ts<<" "<<a[i].ms<<endl;
    // }
    // cout<<endl;
    av(b,m);
    int cs=a[b[0]-1].right_ms;
    if(cs<0){
        cs=0;
    }
    int ms=a[b[0]-1].ms;
    for(int i=1;i<m;i++){
        ms=max({ms,cs+a[b[i]-1].left_ms,a[b[i]-1].ms});
        cs+=a[b[i]-1].ts;
        cs=max({cs,a[b[i]-1].right_ms,0ll});
    }
    cout<<ms<<endl;



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