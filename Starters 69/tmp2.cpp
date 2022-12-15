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
#define rep(i,a,b)      for(int i = a; i < b; i++)
#define irep(i, a, b)   for(int i = a; i > b; i--)
#define mem1(a)         memset(a, -1, sizeof(a))
#define mem0(a)         memset(a, 0, sizeof(a))
#define clz             __builtin_clzll			//leading zeroes
#define ctz             __builtin_ctzll			//trailing zeroes
#define ppc             __builtin_popcountll
#define nl				cout << '\n'

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

int sz, n;
vvi table;
 
void build(vi& v){
    table.clear();
    table.assign(n, vi(30, INF));
    rep(j, 0, 30)    rep(i, 0, n)   if(i + (1<<(j - 1)) < n)    table[i][j] = (j ? (table[i][j - 1]|table[i + (1<<(j - 1))][j - 1]) : v[i]);
}

int query(int l, int r){
	if(l > r)	return 0;
    return table[l][__lg(r - l + 1)]|table[r - (1<<__lg(r - l + 1)) + 1][__lg(r - l + 1)];
}
void solve(){
	int a = -1; cin >> n;
	vi v(n); cin >> v;
	build(v);
	rep(i, 0, n){
		//largest x s.t. OR[i x] <= OR[remaining]
		int l = i, r = n - 1, x;
		while(l <= r){
			int k = (l + r) / 2;
			if(query(i, k) <= (query(0, i - 1)|query(k + 1, n - 1)))	x = k, l = k + 1;
			else	r = k - 1;
		}
		if(query(i, x) == (query(0, i - 1)|query(x + 1, n - 1)))	a = max(a, x - i + 1);
	}
	cout << a; nl;
}

signed main(){
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// #endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	rep(i, 0, t){
		solve();
	}
}