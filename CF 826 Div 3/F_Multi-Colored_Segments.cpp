//Edge Case dekhna BC
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

vector<vector<int>>a;
struct NODE{
    // Can be modified according to the question.
    int ans;
    // Setting the value for default value.
    NODE():ans(INT_MAX){}
};
NODE segTree[4*N];
NODE combine(NODE a,NODE b,bool f){
    // Can be modified according to the question.
    NODE c;
    if(f){
        c.ans=max(a.ans,b.ans);
    }
    else{
        c.ans=min(a.ans,b.ans);
    }
    return c;
}
void build(int node,int start,int end,bool f){
    if(start==end){
        // Can be changed according to the question
        int res=0;
        if(f){
            res=INT_MIN;
        }
        else{
            res=INT_MAX;
        }
        segTree[node].ans=res;
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid,f);
    build(2*node+1,mid+1,end,f);
    segTree[node]=combine(segTree[2*node],segTree[2*node+1],f);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind,int val,bool f){
    if(start==end){
        // Can be changed according to the question
        if(f){
            segTree[node].ans=max(segTree[node].ans,val);
        }
        else{
            segTree[node].ans=min(segTree[node].ans,val);
        }
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind,val,f);
    }
    else{
        update1(2*node,start,mid,ind,val,f);
    }
    segTree[node]=combine(segTree[2*node],segTree[2*node+1],f);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r,bool f){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return segTree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r,f);
    NODE rq=query(2*node+1,mid+1,end,l,r,f);
    return combine(lq,rq,f);
}
void solve()
{
    int n;cin>>n;
    a.clear();
    a.resize(0);
    a.resize(n,vi(4));
    fl(i,0,n){
        e3(l,r,c);
        a[i]={l,r,c,i};
    }
    sort(all(a));
    // build the segment tree from left to right. With maximum r, for each color. Ranges would be color rather than l or r.
    // Initially for maximum r, I would initilize them with INT_MIN
    build(1,0,n-1,true);
    int res[n];
    bool f=true;
    for(int i=0;i<n;i++){
        int num=a[i][2];
        
    }
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