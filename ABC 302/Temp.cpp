#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

#define ll              long long
#define int				ll
#define pb              push_back
#define ppb             pop_back
#define pf              push_front
#define ppf             pop_front
#define all(x)          (x).begin(), (x).end()
#define uniq(v)         (v).erase(unique(all(v)), (v).end())
#define sz(x)           (int)((x).size())
#define fr              first
#define sc              second
#define vi              vector<int>
#define vvi				vector<vi>
#define pii             pair<int, int>
#define vpii			vector<pii>
#define vvpii			vector<vpii>
#define rep(i,a,b)      for(int i = a; i < b; i++)
#define irep(i, a, b)   for(int i = a; i > b; i--)
#define mem1(a)         memset(a, -1, sizeof(a))
#define mem0(a)         memset(a, 0, sizeof(a))
#define clz             __builtin_clzll			//leading zeroes
#define ctz             __builtin_ctzll			//trailing zeroes
#define ppc             __builtin_popcountll
#define nl				cout << '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)

template<typename T>
istream &operator>>(istream &in, vector<T>& v){
    for(int i = 0; i < v.size(); i++)
        in >> v[i];
    return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T>& v){
    for(int i = 0; i < v.size(); i++)
        out << v[i] << " ";
    return out;
}
template<typename T1, typename T2>istream& operator>>(istream& in, pair<T1, T2>& p){ in >> p.fr >> p.sc; return in; }
template<typename T1, typename T2>ostream& operator<<(ostream& out, pair<T1, T2>& p){ out << p.fr << " " << p.sc << " "; return out; }

const ll INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
const int MAX = numeric_limits<int>::max();
const int MIN = numeric_limits<int>::min();

const int N = 0;

int egcd(int a, int b, int& x, int& y, int mod){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	int x1, y1, g = egcd(b, a % b, x1, y1, mod);
	x = y1 % mod, y = ((x1 - (a / b)*y1) % mod + mod) % mod;
	return g;
}

void solve(){
	int n, m; cin >> n >> m;
	vector<string> v(n); cin >> v;
	rep(i, 0, n)	rep(j, 0, m){
		if(i + 4 < n && j + 4 < m){
			if(v[i][j] == 's' && v[i + 1][j + 1] == 'n' && v[i + 2][j + 2] == 'u' && v[i + 3][j + 3] == 'k' && v[i + 4][j + 4] == 'e'){
				rep(k, 0, 5)	cout << i + k + 1 << " " << j + k + 1 << endl;
				return;
			}
		}
		if(i - 4 >= 0 && j - 4 >= 0){
			if(v[i][j] == 's' && v[i - 1][j - 1] == 'n' && v[i - 2][j - 2] == 'u' && v[i - 3][j - 3] == 'k' && v[i - 4][j - 4] == 'e'){
				rep(k, 0, 5)	cout << i - k + 1 << " " << j - k + 1 << endl;
				return;
			}
		}
		if(i + 4 < n){
			if(v[i][j] == 's' && v[i + 1][j] == 'n' && v[i + 2][j] == 'u' && v[i + 3][j] == 'k' && v[i + 4][j] == 'e'){
				rep(k, 0, 5)	cout << i + k + 1 << " " << j + 1 << endl;
				return;
			}
		}
		if(i - 4 >= 0){
			if(v[i][j] == 's' && v[i - 1][j] == 'n' && v[i - 2][j] == 'u' && v[i - 3][j] == 'k' && v[i - 4][j] == 'e'){
				rep(k, 0, 5)	cout << i - k + 1 << " " << j + 1 << endl;
				return;
			}
		}
		if(j + 4 < m){
			if(v[i][j] == 's' && v[i][j + 1] == 'n' && v[i][j + 2] == 'u' && v[i][j + 3] == 'k' && v[i][j + 4] == 'e'){
				rep(k, 0, 5)	cout << i + 1 << " " << j + k + 1 << endl;
				return;
			}
		}
		if(j - 4 >= 0){
			if(v[i][j] == 's' && v[i][j - 1] == 'n' && v[i][j - 2] == 'u' && v[i][j - 3] == 'k' && v[i][j - 4] == 'e'){
				rep(k, 0, 5)	cout << i + 1 << " " << j - k + 1 << endl;
				return;
			}
		}
	}
}

signed main(){
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin >> t;
	rep(i, 0, t){
		solve();
	}
}