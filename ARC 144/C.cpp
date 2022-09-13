#include <bits/stdc++.h>
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

void solve(){
	int n, znext = 0, zcur = 0; cin >> n;
	set<int> st;
	rep(i, 0, n){
		int x; cin >> x;
		if(x == 0)	zcur++;
		if(!st.count(x))	st.insert(x);
		else	znext++;
	}
	while(sz(st) > 1){
		set<int> st1;
		int a = *st.begin(), z1 = 0; st.erase(st.begin());
		while(sz(st)){
			int b = *st.begin(); st.erase(st.begin());
			if(!st1.count(b - a))	st1.insert(b - a);
			else	z1++;
			a = b;
		}
		swap(st, st1);
		if(zcur)	st.insert(0);
		zcur = znext;
		znext = z1;
	}
	if(st.empty())	cout << 0;
	else	cout << *st.begin(); nl;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; cin >> t;
	rep(i, 0, t){
		solve();
	}
}