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
void solve()
{
	//We will calculate for each bit.
	//We will use array prec(n,2),
	//prec(i,0) will tell the answer till ith query if in
	//starting we have this bit as 0
	
	//Similarly prec(i,1) will tell the answer till ith query
	//if in starting we have this bit as 1
	
	//ans(i) will the answer till ith query. So for answering
	//(i+1)th query we can get the answer as : suppose ans(i) is 0,
	//then our answer will be prec(i+1,0), else prec(i+1,1)
	//--->We will do this for all bits 32 bits.
	
	//Time complexity : O(N*32)
	
	e2(n,c);
	vector<pii>qr;
	for(int i=0;i<n;i++){
		e2(l,r);qr.pb({l,r});
	}
	
	
	int prec[n+1][32][2];//prec(i,j,k) will tell the answer of (jth) bit till (ith) query 
	//if it was k(0 or 1) in the starting.
	for(int k=0;k<2;k++){
		for(int j=0;j<32;j++){
			prec[0][j][k]=k;
		}
	}
	
	
	
	//For each bit calculating till (i th)
	for(int k=0;k<2;k++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<32;j++){
				int num=((1<<j)&qr[i-1].ss);
				if(num){
					num=1;
				}
				if(qr[i-1].ff==1){
					prec[i][j][k]=prec[i-1][j][k]&num;
				}		
				else if(qr[i-1].ff==2){
					prec[i][j][k]=prec[i-1][j][k]|num;
				}
				else{
					prec[i][j][k]=prec[i-1][j][k]^num;
				}
			}
		}
	}
	
	int ans[n+1][32];
	for(int j=0;j<32;j++){
		int num=(1<<j)&c;
		if(num){
			num=1;
		}	
		ans[0][j]=num;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<32;j++){
			int num=ans[i-1][j];
			ans[i][j]=prec[i][j][num];
		}	
	}
	vector<int>res;
	for(int i=1;i<=n;i++){
		int cnt=1;
		int num=0;
		for(int j=0;j<32;j++){
			if(ans[i][j]){
				num+=(cnt);
			}
			cnt*=2;
		}
		res.pb(num);
	}
	for(auto v:res){
		cout<<v<<endl;
	}
	
	 
	
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1;
	// cin >> t;
	fl(i, 1, t + 1) {
		solve();
	}
	return 0;
}