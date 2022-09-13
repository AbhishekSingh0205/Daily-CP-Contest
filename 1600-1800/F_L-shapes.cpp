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
const int dx[3] = {-1, 0, 1}, dy[3] = {-1, 0, 1};

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
    /*
        Hum har * ko ake number denge, if agar wo visited hai, uske near koi aur visited hai to not possible
        Possible L : 
        **      or    **        or     *             or    *
        *              *               **                 **
    */
    int n, m;
	cin >> n >> m;
	char g[n][m];
	int id[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> g[i][j];
			id[i][j] = 0;
		}
	}
	int curr = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '*') {
				vector<pair<int, int>> adjh, adjv;
				if (i > 0 && g[i - 1][j] == '*') {
					adjh.emplace_back(i - 1, j);
				}
				if (i < n - 1 && g[i + 1][j] == '*') {
					adjh.emplace_back(i + 1, j);
				}
				if (j > 0 && g[i][j - 1] == '*') {
					adjv.emplace_back(i, j - 1);
				}
				if (j < m - 1 && g[i][j + 1] == '*') {
					adjv.emplace_back(i, j + 1);
				}
				if (adjh.size() == 1 && adjv.size() == 1) {
					if (id[i][j] == 0) {id[i][j] = curr;}
					else {cout << "NO\n"; return;}
					if (id[adjh[0].first][adjh[0].second] == 0) {id[adjh[0].first][adjh[0].second] = curr;}
					else {cout << "NO\n"; return;}
					if (id[adjv[0].first][adjv[0].second] == 0) {id[adjv[0].first][adjv[0].second] = curr;}
					else {cout << "NO\n"; return;}
					curr++;
				}
				else if (adjh.size() > 1 || adjv.size() > 1) {
					cout << "NO\n"; return;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '*') {
				if (id[i][j] == 0) {cout << "NO\n"; return;}
				else {
					for (int x = 0; x < 3; x++) {
						for (int y = 0; y < 3; y++) {
							if (0 <= i + dx[x] && i + dx[x] < n) {
								if (0 <= j + dy[y] && j + dy[y] < m) {
									if (id[i + dx[x]][j + dy[y]] != id[i][j] && id[i + dx[x]][j + dy[y]] != 0) {
										cout << "NO\n"; return;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "YES\n";

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