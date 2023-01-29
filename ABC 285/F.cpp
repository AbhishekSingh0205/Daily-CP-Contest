#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;

#define ll              long long
// #define int				ll
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
vvi tree;
string s;

void build(){
	sz = n;
	while(ppc(sz) != 1)	sz++;
	tree.assign(2*sz - 1, vi(26));
	rep(i, 0, n)	tree[i + sz - 1][s[i] - 'a'] = 1;
	irep(i, sz - 2, -1)	rep(j, 0, 26)	tree[i][j] = tree[2*i + 1][j] + tree[2*i + 2][j];
}

vi query(int l, int r, int low = 0, int high = sz - 1, int cur = 0){
	vi v(26);
	if(r < low || high < l)	return v;
	else if(l <= low && high <= r)	return tree[cur];
	else{
		vi a = query(l, r, low, (low + high) / 2, 2*cur + 1);
		vi b = query(l, r, (low + high) / 2 + 1, high, 2*cur + 2);
		rep(i, 0, 26)	v[i] = a[i] + b[i];
		return v;
	}
}

void upd(int pos, char c){
	int x = pos + sz - 1;
	tree[x][s[pos] - 'a'] = 0;
	s[pos] = c;
	tree[x][s[pos] - 'a'] = 1;
	while(x){
		x = (x - 1) / 2;
		rep(j, 0, 26)	tree[x][j] = tree[2*x + 1][j] + tree[2*x + 2][j];
	}
}

void solve(){
	cin >> n >> s;
	build();
	set<int> inv;
	rep(i, 1, n)	if(s[i] < s[i - 1])	inv.insert(i);
	int q; cin >> q;
	while(q--){
		int t, a; cin >> t >> a; a--;
		if(t == 1){
			char c; cin >> c;
			upd(a, c);
			if(a + 1 < n){
				if(s[a + 1] > s[a])	inv.erase(a + 1);
				else if(s[a + 1] < s[a])	inv.insert(a + 1);
			}
			if(a){
				if(s[a] > s[a - 1])	inv.erase(a);
				else if(s[a] < s[a - 1])	inv.insert(a);
			}
		}
		else{
			int b; cin >> b; b--;
			auto it = inv.upper_bound(a);
			if(it != inv.end() && *it <= b){
				cout << "No"; nl; continue;
			}
			vi v = query(a, b);
			bool f = 0;
			rep(i, s[a] - 'a' + 1, s[b] - 'a')	if(tree[0][i] != v[i]){
				cout << "No"; nl; f = 1; break;
			}
			if(!f)	cout << "Yes" << endl;
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