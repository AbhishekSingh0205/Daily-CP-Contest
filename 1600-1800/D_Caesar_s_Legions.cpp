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
#define mod 100000000
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
int dp[201][101][11][11];
int n1,n2,c1,c2;
int rec(int i,int hm,int ch,int cf){
    if(i==(n1+n2)){
        return 1;
    }
    if(dp[i][hm][ch][cf]!=-1){
        return dp[i][hm][ch][cf];
    }
    if(ch>c1||cf>c2){
        return 0;
    }
    int ans=0;
    int total=i;
    if(hm<n1){
        if(ch<c1){
            ans+=rec(i+1,hm+1,ch+1,0);
        }
    }
    int cm=total-hm;
    if(cm<n2){
        if(cf<c2){
            ans+=rec(i+1,hm,0,cf+1);
        }
    }
    ans%=mod;
    return dp[i][hm][ch][cf]=ans;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    cin>>n1>>n2>>c1>>c2;
    memset(dp,0,sizeof dp);
    // dp[i][j][t][k]
    /*
        i -> Number of Horseman
        j -> Number of Cowman
        t -> Previous Person
        k -> Number of continous that person 
    */
    dp[0][0][0][0]=1;
    fl(i,0,n1+1){
        fl(j,0,n2+1){
			fl(p,0,2){
				int cn=(p==0)?c1:c2;
				for(int z=0;z<=cn;z++){
					// dp[i][j][p][z] -> Fixed hai.
					if(i<n1 && (p==1||z<cn)){
						dp[i+1][j][0][(p==1?1:z+1)]+=dp[i][j][p][z]%mod;
					}
					if(j<n2 && (p==0||z<cn)){
						dp[i][j+1][1][(p==0?1:z+1)]+=dp[i][j][p][z]%mod;
					}
				}		
			}
        }
    }
	int res=0;
	for(int i=0;i<2;i++){
		int cn=(i==0?c1:c2);
		for(int j=0;j<=cn;j++){
			res+=dp[n1][n2][i][j];
			res%=mod;
		}
	}
	res%=mod;
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