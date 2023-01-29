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
int a1[32];
int a2[32];
int dp[32][2][2][2];
int hb;
// fB=0 if number is greater than L
// lB=0 if number is less than R
int rec(int bitN,int fB,int sB,int f){
    pr(bitN,fB,sB);
    if(bitN<0){
        return 0;
    }
    if(dp[bitN][fB][sB][f]!=-1){
        pr(bitN,fB,sB);
        // pr(dp[bitN][fB][sB]);
        return dp[bitN][fB][sB][f];
    }
    int ans=0;
    if(bitN==hb){
        ans=(1<<hb);
        if(a1[bitN]==0){
            ans+=rec(bitN-1,0,1,1);
        }
        else{
            ans+=rec(bitN-1,1,1,f);
        }
    }
    else{
        if(fB==0){
            ans=(1<<bitN)+1+rec(bitN-1,0,sB,f);
        }
        else{
            if(a1[bitN]==1 && a2[bitN]==1){
                ans=rec(bitN-1,fB,sB,f);
            }
            else{
                if(a1[bitN]==0 && a2[bitN]==1){
                    ans=rec(bitN-1,0,sB,1);
                    ans=max(ans,(1<<bitN)+1+rec(bitN-1,1,sB,1));
                }
                else if(a1[bitN]==0 && a2[bitN]==0){
                    if(f){
                        ans=rec(bitN-1,0,sB,f);
                    }
                    ans=max(ans,(1<<bitN)+1+rec(bitN-1,1,sB,f));
                }
                else{
                    ans=rec(bitN-1,fB,sB,f);
                }
            }
        }
    }
    return dp[bitN][fB][sB][f]=ans;

}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e2(l,r);
    memset(a1,0,sizeof a1);
    memset(a2,0,sizeof a2);
    memset(dp,-1,sizeof dp);
    hb=-1;
    int tmp=r;
    while(tmp){
        hb++;tmp/=2;
    }
    tmp=l;
    int k=0;
    while(tmp){
        if(tmp%2){
            a1[k]=1;
        }
        k++;tmp/=2;
    }
    tmp=r;
    k=0;
    while(tmp){
        if(tmp%2){
            a2[k]=1;
        }
        k++;tmp/=2;
    }
    // pr(hb);
    pra(a1,8);
    pra(a2,8);
    int res=rec(hb,1,1,0);
    cout<<res<<endl;

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