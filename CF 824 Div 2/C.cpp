#include <bits/stdc++.h>
#include <math.h>
// in the name of god,aka allah
// gray sety orz
// C

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define pi pair<long long, long long>
#define pii pair<long long, pair<long long, long long>>
const int maxm = 5e5;
const long long mod = 1e9 + 7;
typedef long long ll;
ll l, r, mid;
ll n, m;
ll dis[maxm], sum[maxm];
ll darage[maxm], ss, mm;
queue<int> q;
vector<pi> g[maxm], z[maxm];
ll sath[maxm];
bool vis[maxm], gos[maxm];
ll pedaret[maxm];
ll get_par(ll v)
{
        if (pedaret[v] == v) return v;
        return pedaret[v] = get_par(pedaret[v]);
}
void merge(ll r, ll q)
{
        if (get_par(r) != get_par(q)) l += max(darage[r], darage[q]) * 1ll * sath[r] * 1ll * sath[q];
        r = get_par(r), q = get_par(q);
        if (r != q)
    {
                if (sath[r] < sath[q]) swap(r, q);
                pedaret[q] = r;
                sath[r] += sath[q];
           
    }
        return;
}
ll pars1[maxm], pars2[maxm];
vector<ll> se[maxm];
set<ll> st;
ll rp[maxm];
pi w[maxm];
ll dp[maxm];
// ll rw[maxm][maxm];
map<ll, ll> mp, pm;
int main()
{
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t;
        cin >> t;
        while (t--)
    {
                cin >> n;
                mp.clear();
                pm.clear();
                int a1, b1, a2, b2, a3, b3, a4, b4;
                
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
        mp[a1]++, pm[b1]++, mp[a2]++, pm[b2]++, mp[a3]++, pm[b3]++;
                if (a1 % 2 == a2 % 2)
        {
                        l = a3 % 2;
                   
        }
                else
        {
                        if (a1 % 2 == a3 % 2) l = a2 % 2;
                        else l = a1 % 2;
                   
        }
                if (b1 % 2 == b2 % 2)
        {
                        r = b3 % 2;
                   
        }
                else
        {
                        if (b1 % 2 == b3 % 2) r = b2 % 2;
                        else r = b1 % 2;
                   
        }
                if (l % 2 == a4 % 2 && r % 2 == b4 % 2) cout << "NO" << endl;
                else
        {
                        if (mp[1] > 1 | mp[n] > 1 | pm[1] > 1 | pm[n] > 1)
            {
                                if (1)
                {
                                        if (mp[1] > 1) r = 1, l = 1;
                                        if (mp[n] > 1) r = 1, l = n;
                                        if (mp[1] > 1 | mp[n] > 1 | pm[1] > 1 | pm[n] > 1) r = n, l = 1;
                                        if (mp[1] > 1 | mp[n] > 1 | pm[1] > 1 | pm[n] > 1) r = n, l = n;
                                        if (a4 == r || b4 == l) cout << "YES" << endl;
                                        else cout << "NO" << endl;
                                   
                }
                           
            }
                        else cout << "YES" << endl;
                   
        }
           
    }
}