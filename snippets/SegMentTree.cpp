#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define pbds tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update>

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

class seg_tree{
private:
	typedef struct node{
		pbds p;
	}node;

	int sz;
	node nd;
	vector<node> tr;

public:
	void build(int n){
		sz = n;
	    while(ppc(sz) != 1)    sz++;
	    tr.assign(2*sz - 1, nd);
	}

	int query(int l, int r, int x, int i = 0, int low = 0, int high = 1e9){
		high = min(high, sz - 1);
	    if(l > high || r < low || l > r)    return 0;
	    else if(l <= low && high <= r)	return tr[i].p.order_of_key({x + 1, -1});
	    return query(l, r, x, 2*i + 1, low, (low + high) / 2) + query(l, r, x, 2*i + 2, (low + high) / 2 + 1, high);
	}

	void upd(int pos, int val, int rem){
		int i = sz - 1 + pos;
		tr[i].p.clear(); tr[i].p.insert({val, 0});
		while(sz != 1){
			i = (i - 1) / 2;
			if(rem != -1){
				auto it = tr[i].p.upper_bound({rem + 1, -1}); it--; tr[i].p.erase(it);
			}
			auto it = tr[i].p.upper_bound({val + 1, -1});
			if(it == tr[i].p.begin())	tr[i].p.insert({val, 0});
			else{
				it--;
				if(it->fr == val)	tr[i].p.insert({val, it->sc + 1});
				else	tr[i].p.insert({val, 0});
			}
			if(i == 0)	break;
		}
	}

	void erase(int l, int r, int x, vi& v, int i = 0, int low = 0, int high = 1e9){
		high = min(high, sz - 1);
	    if(l > high || r < low || l > r)    return;
	 	while(sz(tr[i].p) && tr[i].p.begin()->fr <= x)	tr[i].p.erase(tr[i].p.begin());
	 	if(tr[i].p.begin()->fr<=x && i > sz - 2){
	 		v[i - (sz - 1)] = -1;
	 		return;
	 	}
	    erase(l, r, x, v, 2*i + 1, low, (low + high) / 2); erase(l, r, x, v, 2*i + 2, (low + high) / 2 + 1, high);
	}
};

void solve(){
	int n, q; cin >> n >> q;
	seg_tree st;
	st.build(n);
	vi v(n, -1);
	while(q--){
		int t, i, j; cin >> t >> i >> j;
		if(t == 1){
			st.upd(i, j, v[i]);
			v[i] = j;
            // cerr<<"IN UPD";
            // cerr<<v<<endl;
		}
		else{
			int x; cin >> x;
			cout << st.query(i, j, x); nl;
			st.erase(i, j, x, v);
            // cerr<<"Q";
			
		}
        cout << v; nl;
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