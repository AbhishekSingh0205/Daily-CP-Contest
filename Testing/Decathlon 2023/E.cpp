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
#define mod 2147483647
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
vector<pii> gr[N];
int pare[N][22];
int level[N];
int up[N];
multiset<int>st;
map<pair<int,int>,int>m;
void dfs(int src,int par,int lvl){
    pare[src][0]=par;
    level[src]=lvl;
    for(int i=1;i<22;i++){
        if(pare[src][i-1]>=0) pare[src][i]=pare[pare[src][i-1]][i-1];
    }
    for(auto v:gr[src]){
        if(v.ff!=par){
            dfs(v.ff,src,lvl+1);
        }
    }
}
int lca(int a,int b){
    if(level[a]<level[b]){
        swap(a,b);
    }
    for(int i=21;i>=0;i--){
        if((level[a]-level[b])&(1<<i)){
            a=pare[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=21;i>=0;i--){
        if(pare[a][i]!=pare[b][i]){
            a=pare[a][i];b=pare[b][i];

        }
    }
    return pare[a][0];
}
void dfs2(int src,int par)
{
    for(auto v:gr[src]){
        if(v.ff!=pare[src][0]){
            dfs2(v.ff,src);
        }
    }
    for(auto v:gr[src]){
        if(v.ff!=pare[src][0]){
            up[src]+=up[v.ff];
        }
    }
    if(up[src]*m[{src,pare[src][0]}]) st.insert(up[src]*m[{src,pare[src][0]}]);
}
void solve()
{
    e3(n,k,q);
    st.clear();m.clear();
    for(int i=0;i<n;i++)
    {
        gr[i].resize(0);gr[i].clear();
        for(int j=0;j<22;j++){
            pare[i][j]=-1;
        }
        level[i]=0;
        up[i]=0;
    }
    for(int i=0;i<n-1;i++){
        e3(x,y,wt);x--;y--;
        gr[x].pb({y,wt});
        gr[y].pb({x,wt});
        m[{x,y}]=wt;
        m[{y,x}]=wt;
    }
    dfs(0,-1,0);
    vector<pii>qry(q);
    for(int i=0;i<q;i++)
    {
        e2(x,y); x--;y--;int lc=lca(x,y);
        if(x==y){
            C;
        }
        else if(x==lc||y==lc){
            up[lc]--;
            int val=x^y;val^=lc;
            up[val]++;
        }
        else{
            up[lc]-=2;up[x]++;up[y]++;
        }
    }
    dfs2(0,-1);
    int sum=0;
    for(auto v:st){
        sum+=v;
    }
    int cnt=k;
    while(st.size() && cnt){
        int num=*st.rbegin();sum-=num;
        st.erase(st.find(num));cnt--;
    }
    cout<<sum<<endl;

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