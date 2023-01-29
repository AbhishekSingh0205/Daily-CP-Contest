#include<bits/stdc++.h>
using namespace std;

#define IOS  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll               long long
#define lll              __int128
#define ull              unsigned ll
#define ld               long double
#define pb               push_back
#define pbb              pop_back()
#define vll              vector<ll>
#define vi               vector<int>
#define vvll             vector<vll>
#define pll              pair<ll,ll>
#define vpll             vector<pll>
#define mapll            map<ll,ll>
#define umapll           umap<ll,ll>
#define ff               first
#define ss               second
#define endl             "\n"
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define mem(v,a) memset(v,a,sizeof(v))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
/*********policy Based data structure***/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
/**function**/
// find_by_order(k) -> It returns to an iterator to the kth element (counting from zero) in the set
// order_of_key(k) -> It returns to the number of items that are strictly smaller than our item k
// less_equal<int> -> for same element to have in the set

const int mod = 1e9 + 7;
const int dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << "["<<#x <<"]"<<" "<<"= "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}

/*-------------------------------------------------------------------------*/
ll bin_exp(ll base, ll exp){ if (!exp) return 1; ll ans = 1; while (exp) { if (exp & 1) { ans = ((ans % mod) * (base % mod)) % mod;    exp--;} base = ((base % mod) * (base % mod)) % mod;  exp = exp >> 1; } return ans;}
ll lcm(ll a, ll b) { ll g=__gcd(a,b); ll res=a*(b/g); return res; }

/*--------------------------------------------------------------------*/

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//unordered_map<long long, int, custom_hash> safe_map;

const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462

void dfs_base(ll node, ll par,vll &color,vll adj[],vll &parent){
    parent[node] = par;
    for(auto x: adj[node]){
        if(x != par){
            dfs_base(x,node,color,adj,parent);
        }
    }
} 


vll path_D(ll node,vll adj[],vll &parent){
    vll path;
    path.pb(node);
    ll dummy = node;
    while(parent[dummy] != 0){
        dummy = parent[dummy];
        path.pb(dummy);
    }
    return path;
}
void dfs_color_subtree(ll node,ll par,vll &color,vll adj[]){
    color[node] = 1;
    for(auto x: adj[node]){
        if(x != par){
            dfs_color_subtree(x,node,color,adj);
        }
    }
}

void solve() {
    ll n,q; cin>>n>>q;
    vll adj[n + 1];
    for(int i = 0; i< n- 1; i++){
        ll x,y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }  
    vll value(n);
    cin>>value;
    vll color(n+1,0);
    vll parent(n+1,0);
    dfs_base(1,0,color,adj,parent);
    for(int i = 0; i< q ;i++){
        ll type; cin>>type;
        if(type == 1){
            ll x,y; cin>>x>>y;  
            ll white_color = 0, black_color=0;
            vll first_path = path_D(x,adj,parent);
            vll second_path = path_D(y,adj,parent);
            reverse(all(first_path));
            reverse(all(second_path));
            ll lca = -1;
            ll lca_ind = 0;
            for(int i = 0;i < min(first_path.size(),second_path.size()); i++){
                if(first_path[i] == second_path[i]){
                    lca = first_path[i];
                    lca_ind = i;
                }

                else break;
            }
         
            for(int i = lca_ind+1; i<first_path.size(); i++){
                if(color[first_path[i]] == 1) black_color++;
                else white_color++;
            }
            for(int i = lca_ind+1; i< second_path.size(); i++){
                if(color[second_path[i]] == 1) black_color++;
                else white_color++;
            }
            if(color[lca] == 1) black_color++;
            else white_color++;
            
            if(black_color > white_color){
                for(int i = lca_ind; i< first_path.size(); i++){
                    color[first_path[i]] = 1;
                }
                for(int i = lca_ind; i< second_path.size(); i++){
                    color[second_path[i]] = 1;
                }
            }else if(white_color > black_color){
                for(int i = lca_ind; i< first_path.size(); i++){
                    color[first_path[i]] = 0;
                }
                for(int i = lca_ind; i< second_path.size(); i++){
                    color[second_path[i]] = 0;
                }
            }

        }else if(type == 2){
            ll x; cin>>x;
            dfs_color_subtree(x,parent[x],color,adj);
        }else{
            ll x,y;cin>>x>>y;
            vll first_path = path_D(x,adj,parent);
            vll second_path = path_D(y,adj,parent);
            reverse(all(first_path));
            reverse(all(second_path));
            ll lca = -1;
            ll lca_ind = 0;
            for(int i = 0;i < min(first_path.size(),second_path.size()); i++){
                if(first_path[i] == second_path[i]){
                    lca = first_path[i];
                    lca_ind = i;
                }

                else break;
            }
            ll white_nodes = 0;
            ll black_nodes = 0;
            for(int i = lca_ind+1; i< first_path.size(); i++){
                    if(color[first_path[i]] == 1) black_nodes += value[first_path[i] - 1];
                    else white_nodes += value[first_path[i] - 1];
            }
            for(int i = lca_ind+1; i< second_path.size(); i++){
                    if(color[second_path[i]] == 1) black_nodes += value[second_path[i] - 1];
                    else white_nodes += value[second_path[i] - 1];
            }
            if(color[lca] == 1) black_nodes += value[lca-1];
            else white_nodes += value[lca-1];
            cout<<max(white_nodes,black_nodes)<<endl;
        }
    }
}
 
 
int main()
{
    IOS;
 
#ifndef ONLINE_JUDGE
    freopen("error.txt", "w", stderr);
#endif
    int test = 1;
    // cin >> test;
    for (int i = 1; i <= test; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}