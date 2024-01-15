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
int sqrtll(int n) { int lo=0,hi=3037000499; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
int cbrtll(int n) { int lo=0,hi=2097151; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi*hi<=n) { return hi; } return lo; }
void modVal(int &a)
{
        a%=mod;a+=mod;a%=mod;
}
bool cmp(pii a,pii b){
    if(a.ss>b.ss){
        return false;
    }
    else if(a.ss==b.ss){
        if(a.ff>b.ff){
            return true;
        }
        return false;
    }
    return true;
    
}
int k;
bool is(vector<pii>&v1, pii &pt, long double sl){
    int n=v1.size();
    long double eps=0.00000000001;
    int cnt=0;
    long double inter=pt.ss;
    inter-=(sl*pt.ff);
    for(int i=0;i<n;i++){
        long double x1=sl;
        x1*=v1[i].ff;
        long double y1=x1+inter;
        long double diff=y1-v1[i].ss;
        if(diff<=eps){
            cnt++;
        }
    }
    if(cnt>=k){
        return true;
    }
    return false;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*USE DOUBLE HASHING RATHER THAN SINGLE HASHING !!!!*/
    e2(n,m);cin>>k;
    long double p1=0.0,p2=inf;
    vector<pii>pt1,pt2;
    fl(i,0,n){
        e2(x,y);pt1.pb({x,y});
    }
    fl(i,0,m){
        e2(x,y);pt2.pb({-x,-y});
    }
    sort(all(pt1),cmp);
    long double ans=p2;
    long double eps=0.00000000001;
    while(p2-p1>eps){
        long double mid=(p2+p1)/2;
        if(is(pt2,pt1.back(),mid)){
            ans=mid;
            p2=mid-eps;
        }
        else{
            p1=mid+eps;
        }
    }
    long double num=100;
    long double den=1+ans;
    long double res=num/den;
    cout<<res<<endl;
    
    


}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    // cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}