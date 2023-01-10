//Problem Link : 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize "trapv"
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
#define mod 998244353
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
// Overloading for mod
int dp[302][90311][2];
int a[301];
//0 being +ive and 1 being -ive
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    memset(dp,0,sizeof dp);
    // dp[i][j]=#Suffix with ith element having value i.
    // Ans=Summation(dp[0][j][k]) for each (j,k).
    e1(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // int res=rec(0,0,0,n);
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=90000;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k]%=mod;
                dp[i][j][k]+=mod;
                dp[i][j][k]%=mod;
                // Current Value (j with sign k)
                if(k==0){
                    int newV=a[i+1]+j;
                    dp[i+1][newV][0]+=dp[i][j][k]%mod;
                    newV=a[i+1]-j;
                    if(newV>=0 && j){
                        dp[i+1][abs(newV)][0]+=dp[i][j][k]%mod;
                        dp[i+1][abs(newV)][0]%=mod;
                    }
                    else if(newV<0){
                        dp[i+1][abs(newV)][1]+=dp[i][j][k]%mod;
                        dp[i+1][abs(newV)][1]%=mod;
                    }
                }
                else{
                    int jj=-j;
                    int newV=a[i+1]+jj;
                    if(newV>=0){
                        dp[i+1][abs(newV)][0]+=dp[i][j][k]%mod;
                    }     
                    else{
                        dp[i+1][abs(newV)][1]+=dp[i][j][k]%mod;
                    }
                    newV=a[i+1]-jj;
                    if(jj){
                        if(newV>=0){
                            dp[i+1][abs(newV)][0]+=dp[i][j][k]%mod;
                        }     
                        else{
                            dp[i+1][abs(newV)][1]+=dp[i][j][k]%mod;
                        }
                    }
                }
                
            }
        }
    }
    int res=0;
    for(int i=0;i<=90000;i++){
        for(int k=0;k<2;k++){
            res+=dp[n-1][i][k];
            res%=mod;
        }
    }
    cout<<res<<endl;

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