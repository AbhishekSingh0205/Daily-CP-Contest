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
const int N = 2e6 + 5;
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

int cnt0,cnt1;
bool is;
int tt=0;
void dfs(int src,int par,int c,int col[],vi gr[],int n){
	if(col[src]==1-c){
		pr(src);
		is=false;R;
	}
	if(col[src]==c) R;
	if(col[src]==-1){
		col[src]=c;
		if(src<n){
			if(c==0){
				cnt0++;
			}
			else{
				cnt1++;
			}
		}
	}
	for(auto v:gr[src]){
		if(is==false){
			R;
		}
		if(v!=par){
			dfs(v,src,1-c,col,gr,n);
			if(is==false){
				R;
			}
		}
	}
}
void solve()
{
	e2(n,m);
	int hsh=n;
	set<pair<pii,string>>s;
	vi gr[n+m];int col[n+m];
	memset(col,-1,sizeof col);
	for(int i=0;i<n+m;i++){
		gr[i].resize(0);
	}
	for(int i=0;i<m;i++){
		e2(x,y);x--;y--;es(sx);
		if(s.find({{x,y},sx})!=s.end()){
			C;
		}
		s.insert({{x,y},sx});
		if(sx=="imposter"){
			gr[x].pb(y);
			gr[y].pb(x);
		}
		else{
			gr[x].pb(hsh);
			gr[hsh].pb(x);
			gr[hsh].pb(y);
			gr[y].pb(hsh);
			hsh++;
		}
	}
	// pra(gr,n+11);
	int rem=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(col[i]==-1){
			is=true;cnt0=0,cnt1=0;
			dfs(i,-1,0,col,gr,n);
			if(is==false){
				pr(i);
				cout<<-1<<endl;R;
			}
			ans+=max(cnt0,cnt1);
		}
		
	}
	// if(tt==19){
		// cout<<n<<":"<<m<<"::";
		// for(auto v:s){
			// cout<<v.ff.ff<<":"<<v.ff.ss<<":"<<v.ss<<"::";
		// }
	// }
	pr(ans);
	cout<<ans<<endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1;
	cin >> t;
	fl(i, 1, t + 1) {
		tt++;
		solve();
	}
	return 0;
}