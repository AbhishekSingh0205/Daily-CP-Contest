//Problem Link : 
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
#define __builtin_LIVU()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define av(arr,n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
#define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
#define es(s) string(s); cin >> (s);
#define rz resize
#define vvi vector<vector<int>>
#define sz(s) s.size()
#define mod 2
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
const int N = 2e5 + 5;
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
vi gr[N];
int sz[N];
int tmp;
int dis[N];
int pare[N][22];
vi a;
vi arr;
vector <int> pos(N,-1),bigChild(N,-1),chain(N);

void dfs(int src,int par,int cnt){
    dis[src]=cnt;
    pare[src][0]=par;
    for(int i=1;i<22;i++){
        if(pare[src][i-1]>=0) pare[src][i]=pare[pare[src][i-1]][i-1];
    }
    int mxm=0;
    bigChild[src]=-1;
    for(auto v:gr[src]){
        if(v!=par){
            dfs(v,src,cnt+1);
            sz[src]+=sz[v];
            if(sz[v]>mxm){
                mxm=sz[v];
                bigChild[src]=v;
            }
        }
    }
    sz[src]++;
}
int findK(int src,int k){
    for(int i=21;i>=0 && src!=-1;i--){
        if(k&(1<<i)){
            src=pare[src][i];
        }
    }
    return src;
}
int lca(int a,int b){
    if(dis[a]<dis[b]){
        swap(a,b);
    }
    a=findK(a,dis[a]-dis[b]);
    if(a==b){
        return a;
    }
    for(int i=21;i>=0;i--){
        if(pare[a][i]!=pare[b][i]){
            a=pare[a][i];
            b=pare[b][i];
        }
    }
    return pare[a][0];
}

void dfsHLD(int src,int chainNo){
    // pr(src,pare[src][0],chainNo);
    pos[src]=tmp++;
    arr[tmp-1]=(src);
    chain[src]=chainNo;
    // pr(bigChild[src]);
    if(bigChild[src]!=-1){
        dfsHLD(bigChild[src],chainNo);
    }
    for(auto v:gr[src]){
        if(v!=pare[src][0] && v!=bigChild[src])
        {
            dfsHLD(v,v);
        }
    }
}
struct NODE{
    // Can be modified according to the question.
    int ans;
    // Setting the value for default value.
    NODE():ans(0){}
};
NODE segTree[4*N];
NODE combine(NODE a,NODE b){
    // Can be modified according to the question.
    NODE c;
    c.ans=max(a.ans,b.ans);
    return c;
}
void build(int node,int start,int end){
    if(start==end){
        // Can be changed according to the question
        segTree[node].ans=a[arr[start]];
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind,int val){
    if(start==end){
        // Can be changed according to the question
        segTree[node].ans=val;
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind,val);
    }
    else{
        update1(2*node,start,mid,ind,val);
    }
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return segTree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r);
    NODE rq=query(2*node+1,mid+1,end,l,r);
    return combine(lq,rq);
}
int query(int id,int lca){
    int res=0;
    while(chain[id]!=chain[lca]){
        res=max(res,query(1,0,arr.size()-1,pos[chain[id]],pos[id]).ans);
        id=pare[chain[id]][0];
    }
    res=max(res,query(1,0,arr.size()-1,pos[lca],pos[id]).ans);
    return res;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e2(n,q);
    a.resize(n);
    arr.resize(n);
    fl(i,0,n){
        cin>>a[i];
        sz[i]=0;
        chain[i]=i;
        bigChild[i]=-1;
    }    
    fl(i,0,n-1){
        e2(x,y);x--;y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    dfs(0,-1,0);
    // for (int i=0;i<n;i++) cerr<<i+1<<" -> "<<bigChild[i]+1<<endl;
    tmp=0;// time or index
    // memset(pos,-1,sizeof pos);
    // memset(bigChild,-1,sizeof bigChild);
    dfsHLD(0,0);
    build(1,0,n-1);
    fl(i,0,q){
        e1(x);
        if(x==1){
            e2(node,val);
            node--;
            update1(1,0,n-1,pos[node],val);
        }else{
            e2(p1,p2);p1--;p2--;
            int ans=0;
            // pr(lca(p1,p2));
            ans=max(ans,query(p1,lca(p1,p2)));
            ans=max(ans,query(p2,lca(p1,p2)));
            
            cout<<ans<<" ";
        }
    }
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