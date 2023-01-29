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
vector<char>a;
vi par;
vi gr[1001];
void dfs1(int src,int pare){
    par[src]=pare;
    for(auto v:gr[src]){
        if(v!=pare){
            dfs1(v,src);
        }
    }
}

// Trie Template Snippet Starts
class Vertex{
    public:
        vi isEnd;
        vector<int>next;
        Vertex(int k){
            isEnd.resize(0);
            next.resize(k,-1);
        }
};
class Trie{
    public:
        int K;
        vector<Vertex>nodes;
        Trie(int k){
            K=k;
            nodes.push_back(Vertex(K));
        }
        void add(string s){
            // 
            int cur=0;
            for(auto c:s){
                if(nodes[cur].next[c-'a']==-1){
                    nodes[cur].next[c-'a']=nodes.size();
                    nodes.push_back(Vertex(K));
                }
                cur=nodes[cur].next[c-'a'];
            }
        }
        int find(string s){
            int cur=0;
            for(auto c:s){
                if(nodes[cur].next[c-'a']==-1){
                    return 0;
                }
                cur=nodes[cur].next[c-'a'];
            }
        }
        // lst is just temporary and s is also temporary
        // t.print(0,temp,tmp2)
        void print(int x, vector<bool> &lst, string &s)
        {
            for(int i=0; i<((int)lst.size())-1; i++)
            {
                if(lst[i]) cout<<"   ";
                else cout<<"|  ";
            }
            if(!lst.empty()) cout<<"|--";

            cout<<x<<' '<<s<<' '<<' ';
            for(auto v:nodes[x].isEnd){
                cout<<v<<" ";
            }
            cout<<endl;

            int mx = -1;
            for(int i=0; i<K; i++)
                if(nodes[x].next[i] != -1)
                    mx = i;
            
            lst.push_back(false);
            for(int i=0; i<K; i++)
            {
                if(nodes[x].next[i] != -1)
                {
                    s.push_back('a' + i);
                    if(i == mx) lst.back() = true;

                    print(nodes[x].next[i], lst, s);

                    s.pop_back();
                }
            }
            lst.pop_back();
            return;
        }
        void pb(int curr,char c,int qType){
            if(nodes[curr].next[c-'a']==-1){
                nodes[curr].next[c-'a']=nodes.size();
                nodes.push_back(Vertex(K));
            }
            curr=nodes[curr].next[c-'a'];
            if(qType==0||nodes[curr].isEnd.size()==0){
                nodes[curr].isEnd.pb(1);
            }
            else{
                int num=nodes[curr].isEnd.back();
                nodes[curr].isEnd.pop_back();
                num++;
                nodes[curr].isEnd.pb(num);
            }
        }
        int dfs(int curr){
            int ans=0;
            int sum=0;
            int sumsq=0;
            for(auto v:nodes[curr].isEnd){
                sum+=v;
                sumsq+=(v*v);
            }
            sum*=sum;
            sum-=sumsq;
            sum/=2;
            ans+=sum;
            for(int i=0;i<26;i++){
                if(nodes[curr].next[i]!=-1){
                    ans+=dfs(nodes[curr].next[i]);
                }
            } 
            return ans;
        }
};
// Trie Template Ends

void dfs(int src,int curr, Trie &t,int qType,int val){
    // pr(src,curr,qType);
    t.pb(curr,a[src],qType);
    int arr[26];memset(arr,0,sizeof arr);
    for(auto v:gr[src]){
        if(v!=par[src]){
            int tmp=curr;
            tmp=t.nodes[curr].next[a[src]-'a'];
            arr[a[v]-'a']++;
            if(tmp==1){
                arr[a[v]-'a']=1;
            }
            int tVal=max(arr[a[v]-'a'],val);
            if(tVal==1||tmp==1){
                dfs(v,tmp,t,0,tVal);
            }
            else{
                dfs(v,tmp,t,1,tVal);
            }
            // dfs(v,tmp,t);
        }
    }
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
        Har ake node ke liye wapas se dfs krenge and will store every string.
    */
    e1(n);
    a.resize(0);
    a.resize(n);
    fl(i,0,n)cin>>a[i];
    // pr(a);
    for(int i=0;i<n;i++){
        gr[i].resize(0);
    }
    fl(i,0,n-1){
        e2(x,y);x--;y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    par.resize(0);
    par.resize(n,-1);
    dfs1(0,-1);
    // pr("Hello");
    vi res(n,0);
    for(int i=0;i<n;i++){
        Trie t(26);
        // pr(i,"S");
        dfs(i,0,t,0,1);
        // pr(i,"D");
        res[i]=t.dfs(0)+1;
        // vector<bool>tmp;
        // string tmp2;
        // t.print(0,tmp,tmp2);
    }
    e1(q);
    for(int i=0;i<q;i++){
        e1(x);
        x--;
        cout<<res[x]<<endl;
    }
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