#include <bits/stdc++.h>
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
// #define endl             "\n"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define mem(v,a) memset(v,a,sizeof(v))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
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

const int N = 1e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r) uniform_int_distribution<long long>(l,r)(rng)


vector<long long> par(N,-1);

long long find_dsu(long long n)
{
    if (par[n]<0) return n;
    return par[n]=find_dsu(par[n]); //path compression
}

void union_dsu(long long a, long long  b)
{
    a=find_dsu(a);
    b=find_dsu(b);
    if (a==b) return;
    // union by size
    if (abs(par[a])<abs(par[b]))    //make a the larger set
        swap(a,b);
    // a-> larger set is parent
    par[a]+=par[b];
    par[b]=a;
}
// Random Tree generator
vector<vector<int>> random_graph(int n,bool dir=0,bool tree=1,int m=0){
    vector<vector<int>> adj(n+1);
    if(tree){
        for(int i=2;i<=n;i++){
            int x = random(1,i-1);
            adj[x].push_back(i); if(!dir) adj[i].push_back(x);
        }
        return adj;
    }
    set<pair<int,int>> st;
    for(;st.size()<m;){
        int a = random(1,n); int b = random(1,n);
        if (find_dsu(a)==find_dsu(b))   // not connected
            continue;
        if(a==b) continue;
        if(!dir && a>b) swap(a,b);
        st.insert({a,b});
        union_dsu(a,b);
    }
    for(auto p : st) {
        adj[p.first].push_back(p.second);
        if(!dir) adj[p.second].push_back(p.first);
    }
    return adj;
}
signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(atoi(argv[1]));

    // generate test cases with same format as given in problem
    int a = 500;
        //  assert(a>= 2 && a <= 100);
         int q = 5*a;
         cout<<a<<" "<<q<<endl;
        
        vector<vector<int>> x =random_graph(a);
        set <pair<int,int>> st;
        int n= x.size();
        for (int i=1;i<n;i++)
        {
        int sz=x[i].size();
        for (int j=0;j<sz;j++)
        {
            pair <int,int> p1={i,x[i][j]},p2={x[i][j],i};
            if (st.find(p1)==st.end() && st.find(p2)==st.end())
                st.insert(p1);
        }
        }
         for (auto &pr: st)
        cout<<pr.first<<" "<<pr.second<<endl;
        for(int i = 0; i < a; i++){
            long long x = random(1,500);
            cout<<x<<" ";
        }
        cout<<endl;
        for(int i = 0; i < q; i++){
            int type = random(1,3);
            assert(type >= 1 && type <= 3);

            if(type == 1){
                int first_node = random(1,a);
                int second_node = random(1,a);
                assert(first_node >= 1 && first_node <= a);
                assert(second_node >= 1 && second_node <= a);                
                cout<<1<<" "<<first_node<<" "<<second_node<<endl;
            }else if(type == 2){
                int node_subtree;
                node_subtree = random(1,a);
                assert(node_subtree >= 1 && node_subtree <= a);                
                cout<<2<<" "<<node_subtree<<endl;
            }
            else{
                int first_node = random(1,a);
                int second_node = random(1,a);
                assert(first_node >= 1 && first_node <= a);
                assert(second_node >= 1 && second_node <= a);
                cout<<3<<" "<<first_node<<" "<<second_node<<endl;
            
            }
        }
    return 0;
}