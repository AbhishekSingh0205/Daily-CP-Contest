/*

*/
/*
Qg3
g++ -std=c++17 -O2 -Wall a.cpp -o test

*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vp vector<pi>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
#define For(i, a, b) for (ll i = a; i < b; i++)
#define debug2(x, y) cout << "Debug " << #x << " -> " << x << " | " << #y << " -> " << y << endl;
#define debug3(x, y, z) cout << "Debug " << #x << " -> " << x << " | " << #y << " -> " << y << " | " << #z << " -> " << z << endl;
#define debug(x) cout << "Debug " << #x << " -> " << x << endl;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mint map<int, int>
#define mall map<ll, ll>
#define gu(a, s) get<a>(s)
#define tin tuple<ll, ll, ll>
#define ter(x, y, z) ((x) ? y : z)
#define endl "\n"

/*

- Inna and Dima
    Form directed graph, find is there is a cycle or not.
    Also if no cycle find is there is aleast 1 path with length 4.

- Jzzhu and Cities
    Mayb binary search on answer and do dijktras in check function...
    Processs each component differently, add the minimum of component with train and others as dijktra says.
    (Both above ideas are totally wrong.)

- Array and Operations
    always divide with prime number
    find prime divisors of every number
    form a graph (weight is gcd's prime factorization (number of primes))
    pick the edge with maximum weight remove it and upate the 'a[i]' values..

*/

const ll maxn = 1e2 + 5;
const ll nax = 1e6 + 2;
const ll max_val = 5e4 + 10;
const ll mod = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    vll v(n);
    for (auto &x : v)
        cin >> x;
    vll z = v;
    vll temp = v;
    sort(all(v));
    if (v == z)
    {
        cout << 0 << endl;
        return;
    }
    reverse(all(z));
    if (z == v)
    {
        cout << z[n - 1] << endl;
        return;
    }
    v = temp;

    ll mn = 0LL;

    ll dist = 0LL;
    for (ll j = 0; j < n; j++)
    {
        //	debug2(mn, v[j]);
        if (mn > v[j])
        {
            ll diff = mn + v[j];
            ll cnt = diff / 2;
            if (diff % 2)
                cnt++;
            // debug(cnt);
            dist = max(dist, cnt);
        }
        else
        {
            mn = v[j];
        }
    }
    // debug(dist);
    for (int i = 0; i < n; i++)
        v[i] = abs(v[i] - dist);

    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            cout << -1 << endl;
            return;
        }
    }
    cout << dist << endl;
}

bool TestCase1 = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("in0.txt", "r", stdin);
    // freopen("in0.txt", "w", stdout);

    ll t;
    t = 1;
    if (TestCase1)
    {
        cin >> t;
    }
    int cnt = 1;
    while (t--)
    {
        solve();
        cnt++;
    }
    return 0;
}

// template<typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// template<class key, class value, class cmp = less<key>>
// using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

// find_by_order(ind) returns iterator to element at ind starting from 0
// order_of_key(val) returns index of element having value = val starting from