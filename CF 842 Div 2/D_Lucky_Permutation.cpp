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
// Overloading for mod

int rnk[N];
int parent[N];
int find(int a){
    // pr(a,parent[a]);
    if(parent[a]==a){
        return a;
    }
    return parent[a]=find(parent[a]);
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
    {
        return;
    }
    // a->b
    if(rnk[a]>rnk[b]){
        swap(a,b);
    }
    parent[a]=b;
    rnk[b]+=rnk[a];
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e1(n);
    int a[n+1];
    fl(i,1,n+1){
        cin>>a[i];
    }
    fl(i,0,n+1){
        parent[i]=i;
        rnk[i]=1;
    }    
    int vis[n+1];memset(vis,0,sizeof vis);
    int i=1;
    // pr("hjere");
    while(i<=n){
        // pr(i);
        if(vis[i]==1){
            i++;C;
        }
        if(a[i]==i){
            vis[i]=1;
            join(i,a[i]);
            i++;
        }   
        else{
            // pr("H1");
            join(i,a[i]);
            // pr("don");
            int p=i;
            vis[i]=1;
            vis[a[i]]=1;
            i=a[i];
            while(a[i]!=p){
                vis[a[i]]=1;
                join(i,a[i]);
                i=a[i];
            }
            // pr(i);
            i=p;
            i++;
        }
    }
    // pr("here");
    int cyc=0;
    fl(i,1,n+1){
        int x=find(i);
        if(x==i){
            cyc++;
        }
    }
    int ans=inf;
    fl(i,1,n){
        int num=cyc;
        if(find(i)!=find(i+1)){
            num--;
        }
        if(find(i)==find(i+1)){
            num++;
        }
        ans=min(ans,n-num);
    }
    cout<<ans<<endl;




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