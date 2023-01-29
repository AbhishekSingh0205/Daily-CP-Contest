#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld double
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define YY cout<<"YES"
#define NN cout<<"NO"
#define yy cout<<"Yes"
#define nn cout<<"No"
#define set_bits __builtin_popcountll
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define fill1(a,x) for (auto &it: a) it=x;
#define fill2(a,x) for (auto &v: a) { for (auto &it: v) it=x; }
#define endl '\n'   //not to be used in interactive problems
#define random(l,r,T) uniform_int_distribution<T>(l,r)(rng)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int Dx[]={0,1,1,1,0,-1,-1,-1};
int Dy[]={1,1,0,-1,-1,-1,0,1};


// ********     Policy Based Data Structures     ********
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value> using omap = tree <key,value,less<key>,rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k) -> returns iterator to kth element from start 0
// order_of_key(k) -> returns count of elements < k


// ********     Debug Helper     ********
vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while(!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}

void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss; ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

template<typename C, 
         typename T = std::decay_t<decltype(*begin(std::declval<C>()))>,
         typename std::enable_if<!std::is_same<C, std::string>::value>::type* = nullptr
         >
std::ostream &operator<<(std::ostream &os, const C &container)
{
  bool first = true;
  std::stringstream ss; 
  ss << '[';
  for(const auto &x : container){
    if (!first){
      ss << ", ";
    }
    first = false;
    ss << x;
  }
  ss << ']';
  return os << ss.str();
}

#ifndef ONLINE_JUDGE
    #define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
    #define debug(...) 42
#endif


// ********     Useful Fuctions     ********
ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll binExp(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=M) { a = a % m; return binExp(a,m-2,m); }        // only for prime m
ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
ll sqrtll(ll n) { ll lo=0,hi=3037000499; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
ld sqrtld(ll n) { ld lo=0,hi=3037000499; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }
ll cbrtll(ll n) { ll lo=0,hi=2097151; while (hi-lo>1) { ll m=(hi+lo)/2; if (m*m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi*hi<=n) { return hi; } return lo; }
ld cbrtld(ll n) { ld lo=0,hi=2097151; while (hi-lo>eps) { ld m=(hi+lo)/2; if ((n-m*m*m)>eps) { lo=m; } else { hi=m-eps; }} return lo; }
void init_usaco() { freopen("input.txt","r",stdin); freopen("output.txt","w",stdout); }


// ********     Input/Output Template     *********
template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}


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

vector<vector<int>> random_graph(int n,bool dir=0,bool tree=1,int m=0){
    vector<vector<int>> adj(n+1);
    if(tree){
        for(int i=2;i<=n;i++){
            int x = random(1,i-1,int);
            adj[x].push_back(i); if(!dir) adj[i].push_back(x);
        }
        return adj;
    }
    set<pair<int,int>> st;
    for(;st.size()<m;){
        int a = random(1,n,int); int b = random(1,n,int);
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

const int limit_t=1e3,limit_n=1e3,limit_q=1e5,sum_of_n_over_t=1e3,sum_of_q_over_t=1e5;

void test(string path, int i)
{
    freopen(path.c_str(), "w", stdout); // stdout <- file stream
    if(i == 0)
    {
        cout<<"1"<<endl;
        cout<<"11"<<endl;
        cout<<"d a d d a d e e e e e"<<endl;
        cout<<"1 2"<<endl;
        cout<<"1 5"<<endl;
        cout<<"2 3"<<endl;
        cout<<"2 4"<<endl;
        cout<<"3 8"<<endl;
        cout<<"3 9"<<endl;
        cout<<"4 10"<<endl;
        cout<<"4 11"<<endl;
        cout<<"5 6"<<endl;
        cout<<"5 7"<<endl;
        cout<<"5"<<endl;
        cout<<"2"<<endl;
        cout<<"1"<<endl;
        cout<<"4"<<endl;
        cout<<"6"<<endl;
        cout<<"3"<<endl;
    }
    else if (i==1)
    {
        int t=random(1,5,int);
        cout<<t<<endl;
        while (t--)
        {
            int n=random(1,20,int);
            cout<<n<<endl;
            for (int i=0;i<n;i++)
            {
                char ch=random('a','d',char);
                cout<<ch<<" ";
            }
            cout<<endl;
            vector<vector<int>> x =random_graph(n);
            set <pair<int,int>> st;
            int m= x.size();
            for (int i=1;i<m;i++)
            {
                int szz=x[i].size();
                for (int j=0;j<szz;j++)
                {
                    pair <int,int> p1={i,x[i][j]},p2={x[i][j],i};
                    if (st.find(p1)==st.end() && st.find(p2)==st.end())
                        st.insert(p1);
                }
            }
            for (auto &pr: st)
                cout<<pr.first<<" "<<pr.second<<endl;
            int q=random(1,10,int);
            cout<<q<<endl;
            while (q--)
            {
                int node=random(1,n,int);
                cout<<node<<endl;
            }
        }
    }
    else if (i==2 || i==7)
    {
        int t=10;
        cout<<t<<endl;
        while (t--)
        {
            int n=100;
            cout<<n<<endl;
            for (int i=0;i<n;i++)
            {
                char ch=random('a','d',char);
                cout<<ch<<" ";
            }
            cout<<endl;
            vector <vector<int>> adj=random_graph(n);
            set <pair<int,int>> edges;
            for (int i=1;i<=n;i++)
            {
                for (auto &it: adj[i])
                {
                    pair <int,int> pr={min(i,it),max(i,it)};
                    edges.insert(pr);
                }
            }
            vector <pair<int,int>> vec;
            for (auto &pr: edges)
                vec.push_back(pr);
            random_shuffle(all(vec));
            for (auto &pr: vec)
                cout<<pr<<endl;
            int q=random(1,10000,int);
            cout<<q<<endl;
            while (q--)
            {
                int node=random(1,n,int);
                cout<<node<<endl;
            }
        }
    }
    else if(i==3||i==5)
    {
        int t=1;
        cout<<t<<endl;
        while (t--)
        {
            int n=1000;
            cout<<n<<endl;
            for (int i=0;i<n;i++)
            {
                char ch=random('a','d',char);
                cout<<ch<<" ";
            }
            cout<<endl;
            vector <vector<int>> adj=random_graph(n);
            set <pair<int,int>> edges;
            for (int i=1;i<=n;i++)
            {
                for (auto &it: adj[i])
                {
                    pair <int,int> pr={min(i,it),max(i,it)};
                    edges.insert(pr);
                }
            }
            vector <pair<int,int>> vec;
            for (auto &pr: edges)
                vec.push_back(pr);
            random_shuffle(all(vec));
            for (auto &pr: vec)
                cout<<pr<<endl;
            int q=100000;
            cout<<q<<endl;
            while (q--)
            {
                int node=random(1,n,int);
                cout<<node<<endl;
            }
        }
    }
    else
    {
        int t=10;
        cout<<t<<endl;
        while (t--)
        {
            int n=100;
            cout<<n<<endl;
            for (int i=0;i<n;i++)
            {
                char ch=random('a','e',char);
                cout<<ch<<" ";
            }
            cout<<endl;
            vector <vector<int>> adj=random_graph(n);
            set <pair<int,int>> edges;
            for (int i=1;i<=n;i++)
            {
                for (auto &it: adj[i])
                {
                    pair <int,int> pr={min(i,it),max(i,it)};
                    edges.insert(pr);
                }
            }
            vector <pair<int,int>> vec;
            for (auto &pr: edges)
                vec.push_back(pr);
            random_shuffle(all(vec));
            for (auto &pr: vec)
                cout<<pr.ff<<" "<<pr.ss<<endl;
            int q=10000/t;
            cout<<q<<endl;
            while (q--)
            {
                int node=random(1,n,int);
                cout<<node<<endl;
            }
        }
    }
}

void dfsPar(ll node, ll p, vll adj[], vll &par)
{
    par[node]=p;
    for (auto &it: adj[node])
    {
        if (it==p) continue;
        dfsPar(it,node,adj,par);
    }
}

struct node
{
    node *links[26];
    ll cnt=0;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void insertKey(char ch, node *newLink)
    {
        links[ch-'a']=newLink;
    }
    node *gotoRefTrie(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd()
    {
        cnt++;
    }
    ll getCount()
    {
        return cnt;
    }
};

class Trie
{
    private:
        node *root;
    public:
        Trie()
        {
            root=new node();
        }
        void insert(char ch, node *Node)
        {
            if (!Node->containsKey(ch))
                Node->insertKey(ch, new node());
            Node=Node->gotoRefTrie(ch);
            Node->setEnd();
        }
        node *getRoot()
        {
            return root;
        }
};

void insertInTrie(ll nd, ll p, vector <char> &ch, vll adj[], node *root, Trie &ds)
{
    ds.insert(ch[nd],root);
    root=root->gotoRefTrie(ch[nd]);
    for (auto &it: adj[nd])
    {
        if (it==p) continue;
        insertInTrie(it,nd,ch,adj,root,ds);
    }
}

ll calculate(ll nd, ll p, vector <char> &ch, vll adj[], node *root)
{
    if (!root->containsKey(ch[nd])) return 0;
    root=root->gotoRefTrie(ch[nd]);
    ll ans=root->getCount();
    for (auto &it: adj[nd])
    {
        if (it==p) continue;
        ans+=calculate(it,nd,ch,adj,root);
    }
    return ans;
}

ll noOfPaths(ll node, ll p, vector <char> &ch, vll adj[], vll &dp)
{
    if (dp[node]!=-1) return dp[node];
    // using Trie data structure
    Trie ds;
    ll ans=1;
    vll childs;
    for (auto &it: adj[node])
    {
        if (it==p) continue;
        childs.push_back(it);
    }
    ll m=sz(childs);
    if (m==0) return dp[node]=ans;
    insertInTrie(childs[0],node,ch,adj,ds.getRoot(),ds);
    for (ll i=1;i<m;i++)
    {
        // calculate
        ans+=calculate(childs[i],node,ch,adj,ds.getRoot());
        // insert into Trie
        insertInTrie(childs[i],node,ch,adj,ds.getRoot(),ds);
    }
    return dp[node]=ans;
}

void solve(string ipath, string opath)
{
    // output file generate
    freopen(ipath.c_str(), "r", stdin);
    freopen(opath.c_str(), "w", stdout);
    //solution starts
    ll t; cin>>t;
    while (t--)
    {
        ll n; cin>>n;
        vll adj[n];
        vector <char> ch(n); cin>>ch;
        for (ll i=0;i<n-1;i++)
        {
            ll u,v; cin>>u>>v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vll par(n);
        dfsPar(0,-1,adj,par);
        ll q; cin>>q;
        vll dp(n,-1);
        while (q--)
        {
            ll node; cin>>node; node--;
            ll ans=noOfPaths(node,par[node],ch,adj,dp);
            cout<<ans<<endl;
        }
    }
}

int main()
{
    int t = 11;
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif
    for (int i = 0; i <= t; i++)
    {
        string path = to_string(i);
        if (i < 10)
            path = "0" + path;                    // "01" "02" "10"
        string ipath = "RECode/input/input" + path + ".txt"; // ip01.in
        test(ipath, i);
        string opath = "RECode/output/output" + path + ".txt";
        solve(ipath, opath);
    }
}