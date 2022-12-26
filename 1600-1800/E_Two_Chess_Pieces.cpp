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
const int N = 200000;
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
int tme[N];
int tmp=1;
int dis[N];
int pare[N][22];
bool good(int a,int b){
    if(tme[a]>=tme[b]){
        return false;
    }
    return true;
}
void dfs(int src,int par,int cnt){
    tme[src]=tmp;
    tmp++;
    dis[src]=cnt;
    pare[src][0]=par;
    for(int i=1;i<22;i++){
        if(pare[src][i-1]>=0) pare[src][i]=pare[pare[src][i-1]][i-1];
    }
    for(auto v:gr[src]){
        if(v!=par){
            dfs(v,src,cnt+1);
        }
    }
}
int lca(int a,int b){
    if(dis[a]<dis[b]){
        swap(a,b);
    }
    for(int i=21;i>=0;i--){
        if((dis[a]-dis[b])&(1<<i)){
            a=pare[a][i];
        }
    }
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
int findK(int src,int k){
    for(int i=21;i>=0;i--){
        if(k&(1<<i)){
            src=pare[src][i];
        }
    }
    return src;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e2(n,d);
    for(int i=0;i<n;i++){
        gr[i].resize(0);
        gr[i].clear();
        tme[i]=inf;
    }
    fl(i,0,n-1){
        e2(u,v);u--;v--;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    // pra(gr,n);
    memset(pare,-1,sizeof pare);
    memset(dis,0,sizeof dis);
    dfs(0,-1,0);
    // prm(pare,n,22);
    e1(m1);
    av(a1,m1);
    fl(i,0,m1){
        a1[i]--;
    }
    e1(m2);
    av(a2,m2);
    fl(i,0,m2){
        a2[i]--;
    }
    sort(all(a1),good);
    sort(all(a2),good);
    int p0=0,p1=0;
    int i=0,j=0;
    int ans=0;
    while(i<m1 && j<m2){
        if(tme[a1[i]]<tme[a2[j]]){
            int num1=dis[a1[i]]+dis[p0];
            num1-=(2*dis[lca(a1[i],p0)]);
            ans+=num1;
            p0=a1[i];
            if(dis[p0]+dis[p1]-2*dis[lca(p0,p1)]>d){
                if(dis[p0]-dis[lca(p0,p1)]>=d){
                    int newP1=findK(p0,d);
                    ans+=(dis[p1]+dis[newP1]-2*dis[lca(p1,newP1)]);
                    p1=newP1;
                }
                else{
                    int rem=d-(dis[p0]-dis[lca(p0,p1)]);
                    rem=dis[p1]-dis[lca(p0,p1)]-rem;
                    int newP1=findK(p1,rem);
                    ans+=(dis[p1]+dis[newP1]-2*dis[lca(p1,newP1)]);
                    p1=newP1;
                }
            }
            i++;
        }
        else{
            // pr("Going j",j);
            int num1=dis[a2[j]]+dis[p1]-2*dis[lca(p1,a2[j])];
            // pr(num1,lca(p1,a2[j]));
            ans+=num1;
            p1=a2[j];
            if(dis[p1]+dis[p0]-2*dis[lca(p0,p1)]>d){
                if(dis[p1]-dis[lca(p1,p0)]>=d){
                    int newP0=findK(p1,d);
                    ans+=(dis[p0]+dis[newP0]-2*dis[lca(p0,newP0)]);
                    p0=newP0;
                }
                else{
                    int rem=d-(dis[p1]-dis[lca(p0,p1)]);
                    rem=dis[p0]-dis[lca(p0,p1)]-rem;
                    int newP0=findK(p0,rem);
                    ans+=(rem);
                    p0=newP0;
                }
            }
            j++;
        }
    }
    while(i<m1){
        int num1=dis[a1[i]]+dis[p0];
        num1-=(2*dis[lca(a1[i],p0)]);
        ans+=num1;
        p0=a1[i];
        if(dis[p0]+dis[p1]-2*dis[lca(p0,p1)]>d){
            if(dis[p0]-dis[lca(p0,p1)]>=d){
                int newP1=findK(p0,d);
                ans+=(dis[p1]+dis[newP1]-2*dis[lca(p1,newP1)]);
                p1=newP1;
            }
            else{
                int rem=d-(dis[p0]-dis[lca(p0,p1)]);
                rem=dis[p1]-dis[lca(p0,p1)]-rem;
                int newP1=findK(p1,rem);
                ans+=(rem);
                p1=newP1;
            }
        }
        i++;
    }
    while(j<m2){
        int num1=dis[a2[j]]+dis[p1]-2*dis[lca(p1,a2[j])];
        ans+=num1;
        p1=a2[j];
        if(dis[p1]+dis[p0]-2*dis[lca(p0,p1)]>d){
            if(dis[p1]-dis[lca(p1,p0)]>=d){
                int newP0=findK(p1,d);
                ans+=(dis[p0]+dis[newP0]-2*dis[lca(p0,newP0)]);
                p0=newP0;
            }
            else{
                int rem=d-(dis[p1]-dis[lca(p0,p1)]);
                rem=dis[p0]-dis[lca(p0,p1)]-rem;
                int newP0=findK(p0,rem);
                ans+=(rem);
                p0=newP0;
            }
        }
        j++;       
    }
    // pr(i,j);
    // pr(p0,p1);
    ans+=dis[p0];
    ans+=dis[p1];
    cout<<ans<<endl;


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