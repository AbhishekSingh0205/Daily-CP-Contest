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
vi e,o;
int dp[101][101][101][2];
int rec(int i,int j,int sum,int turn){
    int n=e.size()+o.size();
    int rem=e.size()-i+o.size()-j;
    if(rem==1 && turn==1 && n%2==0){
        if(sum%2==0){
            return true;
        }
        return false;
    }
    if(rem==0 && turn==1 && n%2){
        if(sum%2==0){
            return true;
        }
        return false;
    }
    if(dp[i][j][sum][turn]!=-1){
        return dp[i][j][sum][turn];
    }
    int ans=0;
    if(turn==0){
        if(j<o.size()){
            ans=max(ans,rec(i,j+1,sum+1,1));
        }
        if(i<e.size()){
            ans=max(ans,rec(i+1,j,sum,1));
        }
    }
    else{
        if(j<o.size()){
            ans=min(ans,rec(i,j+1,sum,0));
        }
        if(i<e.size()){
            ans=min(ans,rec(i+1,j,sum,0));
        }
    }
    return dp[i][j][sum][turn]=ans;
}
void solve()
{
    e1(n);
    av(a,n);
    fl(i,0,n){
        a[i]=abs(a[i])%2;
    }
    e.clear();
    o.clear();
    fl(i,0,n){
        if(a[i]==0){
            e.pb(a[i]);            
        }
        else{
            o.pb(a[i]);
        }
    }
    if(e.size()==n){
        cout<<"Alice"<<endl;R;
    }
    else if(o.size()==n && n%2==0){
        if(n%4==0){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
        R;
    }
    else if(o.size()==n && n%2){
        cout<<"Alice"<<endl;R;
    }
    for(int i=0;i<e.size();i++){
        for(int j=0;j<o.size();j++){
            for(int k=0;k<o.size();k++){
                dp[i][j][k][0]=-1;
                dp[i][j][k][1]=-1;
            }
        }
    }
    // memset(dp,-1,sizeof dp);
    int ans=rec(0,0,0,0);
    if(ans){
        cout<<"Alice"<<endl;R;
    }
    else{
        cout<<"Bob"<<endl;R;
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