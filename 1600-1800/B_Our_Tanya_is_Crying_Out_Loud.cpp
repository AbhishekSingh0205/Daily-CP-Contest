// Solution of : Abhishek Singh
// DS ALGO USED :
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define e1(a) \
    int a;    \
    cin >> a;
#define e2(a, b) \
    int a, b;    \
    cin >> a >> b;
#define e3(a, b, c) \
    int a, b, c;    \
    cin >> a >> b >> c;
#define av(arr, n)      \
    vector<int> arr(n); \
    fl(i, 0, n) cin >> arr[i];
#define aa(arr, n) \
    int arr[n];    \
    fl(i, 0, n) cin >> arr[i];
#define es(s)  \
    string(s); \
    cin >> (s);
#define vi vector<int>
#define vvi vector<vector<int>>
#define mod 1000000007
#define ff first
#define ss second
#define inf 10e15
#define pii pair<int, int>
#define mii map<int, int>
#define vl(n) cout << n << "\n"
#define vs(n) cout << n << " "
#define el cout << "\n"
#define UB upper_bound
#define LB lower_bound
#define vn(n) cout << n
#define dsc greater<int>()
#define ps(x, y) fixed << setprecision(y) << x
#define R return
// #define B break
#define C continue
int fact[200000];
int dmod(int x) {
	return ((x + mod) % mod);
}
int power(int x, int y)
{
	int res = 1;
	while (y)
	{
		if (y & 1) res = (res * x) % mod;
		x = (x * x) % mod; y >>= 1;
	}
	return res;
}
int nCr(int n, int r) {
	if (r > n) return 0;
	else if (r < 0) return 0;
	else if (r == 0 || r == n)return 1;
	int ans = fact[n];
	ans = (ans * power(fact[n - r], mod - 2)) % mod; ans = (ans * power(fact[r], mod - 2)) % mod;
	return ans;
}
#define YC cout << "YES" \
                << "\n"
#define YS cout << "Yes" \
                << "\n"
#define NC cout << "NO" \
                << "\n"
#define NS cout << "No" \
                << "\n"
#define lcm(a, b) (a / __gcd(a, b)) * b
#define pa(a)        \
    for (auto e : a) \
    cout << e << " "
const int N = 1e6;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

#ifndef ONLINE_JUDGE
#define pra(a, n)               \
    cerr << #a << ":";          \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define prm(mat, row, col)            \
    cerr << #mat << ":\n";            \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p)
{
	return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
	os << "[";
	for (auto &it : p)
		os << it << " ";
	return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << ":" << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
	int idx = str.find(',');
	cerr << str.substr(0, idx) << ":" << t << ",";
	dbs(str.substr(idx + 1), s...);
}
#else
#define pr(...) \
    {           \
    }
#define pra(a, n) \
    {             \
    }
#define prm(mat, row, col) \
    {                      \
    }
#endif
void solve()
{
	int n, k, A, B;
	int ans = 0;
	cin >> n >> k >> A >> B;
	if (k == 1) {
		cout << (n - 1)*A;
		return ;
	}
	while (n) {
		if (n < k) {
			ans += (n - 1) * A;
			break;
		}
		int t = n / k;
		ans += (n - k * t) * A + min((k - 1) * A * t, B);
		n = t;
	}
	cout << ans;
}

int32_t main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	// int t; cin >> t; while (t--)

	solve();

	return 0;
}