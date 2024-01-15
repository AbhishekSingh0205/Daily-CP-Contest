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
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
        Idea : 
        First subtract all the elements by -x. 
        Find the maximum prefix sum now with their maximum length.
        If that length >= k then new sum will be (max Subarray Sum) + (k*2x)
        Else new (max Subarray Sum) + (len*2x).
        
        Now task is to find the maximum prefix sum, which can be foumd using kadane's algo.

        dp[i] is the prefix sum ending till this index.
        Int min_sum is the minimum prefix sum, and it's length.
    */
    e1(n);e2(k,x);
    av(a,n);
    int suff[n];memset(suff,0,sizeof suff);
    for(int i=n-1;i>=0;i--){
        int num=1;
        suff[i]=a[i]-(num*x);
        if(i!=n-1){
            suff[i]+=suff[i+1];
        }
    }
    int pref[n];memset(pref,0,sizeof pref);
    for(int i=0;i<n;i++){
        int num=1;
        pref[i]=a[i]-(num*x);
        if(i){
            pref[i]+=pref[i-1];
        }
    }
    int mnm=0;
    int dp[n];memset(dp,0,sizeof dp);
    for(int i=n-1;i>=0;i--){
        dp[i]=suff[i]-mnm;
        dp[i]=max(dp[i],mnm);
        mnm=min(mnm,suff[i]);
    }
    mnm=0;
    int dp2[n];memset(dp2,0,sizeof dp2);
    for(int i=0;i<n;i++){
        dp2[i]=pref[i]-mnm;
        dp2[i]=max(mnm,dp2[i]);
        mnm=min(mnm,pref[i]);
    }
    pra(pref,n);
    pra(dp2,n);
    int res=0;
    for(int i=0;i<n;i++){
        int sum=0;
        int num=1; 
        for(int j=0;j<k && j+i<n;j++){
            sum=sum+(a[i+j]+(num*x));
            if(i+j+1<n){
                res=max(res,sum+dp[i+j+1]);
            }
            res=max(res,sum);
            if(i+k<n && i){
                res=max(res,sum+dp2[i-1]);
            }
        }
    }
    for(int i=0;i<n-k;i++){
        res=max(res,dp2[i]);
    }
    for(int i=k;i<n;i++){
        res=max(res,dp[i]);
    }
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