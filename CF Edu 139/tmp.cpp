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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int sz, n;
vector<multiset<int>> tree;

void build(vi& v){
    sz = n;
    while(ppc(sz) != 1)    sz++;
    tree.clear();
    tree.resize(2*sz - 1);
    rep(i, 0, n)	tree[i + sz - 1].insert(v[i]);
    irep(i, sz - 2, -1){
    	for(auto a : tree[2*i + 1])	tree[i].insert(a);
    	for(auto a : tree[2*i + 2])	tree[i].insert(a);
    }
}

int query(int l, int r, int i, int low, int high, int val){
   	if(i > sz - 2){
   		if(tree[i].lower_bound(val) == tree[i].end())	return -1;
		return i - (sz - 1);
   	}
    else{
    	if(l <= (low + high) / 2 && tree[2*i + 1].lower_bound(val) != tree[2*i + 1].end())	return query(l, r, 2*i + 1, low, (low + high) / 2, val);
    	else if(r > (low + high) / 2 && tree[2*i + 2].lower_bound(val) != tree[2*i + 2].end())	return query(l, r, 2*i + 2, (low + high) / 2 + 1, high, val);
    	else	return -1;
    }
}

void upd(int pos, int rem, int ins){
	int i = sz - 1 + pos;
	do{
		tree[i].erase(tree[i].find(rem));
		tree[i].insert(ins);
		if(i == 0)	break;
		i = (i - 1) / 2;
	}while(n != 1);
}

void solve(){
	int q; cin >> n >> q;
	vi v(n); cin >> v;
	build(v);
	while(q--){
		int t, a, b; cin >> t >> a >> b;
		if(t == 1){
			upd(a, v[a], b);
			v[a] = b;
		}
		else	cout << query(b, n - 1, 0, 0, sz - 1, a) << endl;
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