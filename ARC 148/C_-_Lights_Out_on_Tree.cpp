/*
    Date 12th September
    Upsolving 
    "Before having any doubt, remember its tree that is every child will have only one     parent."

    Key points :
        1. Pressing a button twice won't change anything
        2. If we know which buttons we need to press for minimum number of buttons, then pressing, then we will get the same number of button presses in any order of pressing those buttons
    
    Let's say we have M(i)={v}, then we need to click on the [v] once and once to all its childrens.

    Let's say we have M(i)={u,v} and [u] is children of [v] then pressing [v] once and then we need to press all its childrens, except [u], as once we pressed the [v] then it fliped all the subtree, means [u] is also filped (which we wanted), now pressing [u] again will be use less. But now we need to press all the childrens of [u], as they also changed.
        Means anynode which is head is already fliped by any parent fliping, then we don't to press that (children's) button again.
    
    Let's say we have M(i)={u,v} and [v] is ancestor of [u], then first we will flip [v], then all its children if notice properly [u] would be flipped twice once by [v], and then by it's children means it wouldn't have changed.
        So we need to press [u] too, then all it's children



    
    Implementation : 
        We need to store the number of childrens of each parent.
        We need to store (parent,child) pair.
        We need to sort the nodes in M according to bfsLevel (not needed)
        Answer would be  :  
            SUMMATION (all childs of M[i] + 1) - 2 * (parent,child in M).
        
        Precedure to calculate #(parent,child in M):
            We will store M in set, and for each [ele] in setM, we will check wether par[ele] is there in setM in O(logM) 
*/
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
int bfsL[N],par[N],cno[N];
vi gr[N];

void solve()
{
    e2(n,q);
    fl(i,0,n){
        bfsL[i]=inf;
        par[i]=n;
        gr[i].clear();
        gr[i].resize(0);
        cno[i]=0;
    }
    fl(i,1,n){
        e1(x);x--;
        gr[i].pb(x);gr[x].pb(i);
        par[i]=x;
    }
    // pra(gr,n);
    // Not Needed from here
    bfsL[0]=0;
    queue<int>qq;
    qq.push(0);
    while(qq.size()){
        int tp=qq.front();
        qq.pop();
        for(auto v:gr[tp]){
            if(bfsL[v]>bfsL[tp]){
                bfsL[v]=bfsL[tp]+1;
                qq.push(v);
            }
        }
    }
    // Not Needed till here
    while(q--){
        set<int>M;
        e1(m);
        for(int i=0;i<m;i++){
            e1(x);x--;
            M.insert(x);
        }
        // pr(M);
        int ans=0;
        for(auto v:M){
            int Ch=gr[v].size();
            if(v){
                Ch--;
            }
            Ch++;
            ans+=Ch;
            if(M.find(par[v])!=M.end()){
                ans-=2;
            }
        }

        cout<<ans<<endl;

    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    // cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}