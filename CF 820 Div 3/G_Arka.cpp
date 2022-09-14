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
/*
Select exacty one interval in [st[i], st[i] + sz(t) - 1] let's call it j. Let the first index after jth interval be k, i.e. 
[st[i]     st[i] + sz(t) - 1]
      [st[j]     st[j] + sz(t) - 1]
                                  [st[k]      st[k] + sz(t) - 1]
then dp[i][x] += dp[k][x - 1]
*/
void solve(){
	string s, t; cin >> s >> t;
	int n = sz(s);
	vi st;
	rep(i, 0, sz(s))	if(s.substr(i, min(sz(s) - i, sz(t))).compare(t) == 0)	st.pb(i);
	int cnt = 0, i = 0;
	while(i < sz(st)){
		int j = i;
		while(j < sz(st) && st[j] <= st[i] + sz(t) - 1)	j++;
		cnt++;
		i = j - 1;
		while(j < sz(st) && st[j] <= st[i] + sz(t) - 1)	j++;
		i = j;
	}
	vvi dp(sz(st), vi(cnt + 1)); if(sz(st))	dp[sz(st) - 1][1] = 1;
	irep(i, sz(st) - 2, -1){
		rep(x, 1, cnt + 1){
            int j = i;
            while(j < sz(st) && st[j] < st[i] + sz(t)){
                auto it = upper_bound(all(st), st[j] + sz(t) - 1);
                if(it == st.end()){
                    if(x == 1)  dp[i][x] = (dp[i][x] + 1) % M;
                    else{
                        j++; continue;
                    }
                }
                else    dp[i][x] = (dp[i][x] + dp[it - st.begin()][x - 1]) % M;
                j++;
            }
        }
	}
    cout<<cnt<<" "<<dp[0][cnt]<<endl;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	rep(i, 0, t){
        //cout << "Case #" << i + 1 << ": ";
		solve();
	}
}