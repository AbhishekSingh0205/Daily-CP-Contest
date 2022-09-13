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

const int N = 0;

void solve(){
    int n, r, c, sr, sc; cin >> n >> r >> c >> sr >> sc; sr--; sc--;
    vector<set<pii>> row(r), col(c);
    row[sr].insert({sc, sc});
    col[sc].insert({sr, sr});
    while(n--){
        char c; cin >> c;
        if(c == 'E' || c == 'W'){
            auto it = row[sr].upper_bound({sc, sc}); it--;
            if(c == 'W')    sc = it->fr - 1;
            else    sc = it->sc + 1;
        }
        else{
            auto it = col[sc].upper_bound({sr, sr}); it--;
            if(c == 'N')    sr = it->fr - 1;
            else    sr = it->sc + 1;
        }
        auto right = row[sr].upper_bound({sc, sc}), left = right;
        int a = sc, b = sc;
        if(right != row[sr].end() && left != row[sr].begin()){
            left--;
            if(right->fr == sc + 1)
                b = right->sc;
                row[sr].erase(right);
            }
            if(left->sc == sc - 1){
                a = left->fr;
                row[sr].erase(left);
            }
        }
        else if(right != row[sr].end()){
            if(right->fr == sc + 1)
                b = right->sc;
                row[sr].erase(right);
            }
        }
        else{
            if(left->sc == sc - 1){
                a = left->fr;
                row[sr].erase(left);
            }
        }
        row[sr].insert({a, b});
        right = col[sc].upper_bound({sr, sr}), left = right;
        a = sr, b = sr;
        if(right != col[sc].end() && left != col[sc].begin()){
            left--;
            if(right->fr == sr + 1)
                b = right->sc;
                col[sc].erase(right);
            }
            if(left->sc == sr - 1){
                a = left->fr;
                col[sc].erase(left);
            }
        }
        else if(right != col[sc].end()){
            if(right->fr == sr + 1)
                b = right->sc;
                col[sc].erase(right);
            }
        }
        else{
            if(left->sc == sr - 1){
                a = left->fr;
                col[sc].erase(left);
            }
        }
        col[sc].insert({a, b});
    }
    cout << sr + 1 << " " << sc + 1; nl;
}

signed main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int t = 1; cin >> t;
	rep(i, 0, t){
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}