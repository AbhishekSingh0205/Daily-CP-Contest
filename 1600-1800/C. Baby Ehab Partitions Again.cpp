//Problem Link : 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
#define pb push_back
#define mp make_pair
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define e1(a) int a; cin>>a;
#define e2(a,b) int a,b; cin>>a>>b;
#define e3(a,b,c) int a,b,c; cin>>a>>b>>c;
#define __builtin_LIVU()  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define av(arr,n) vector<int> arr(n); fl(i,0,n) cin>>arr[i];
#define aa(arr,n) int arr[n]; fl(i,0,n) cin>>arr[i];
#define es(s) string(s); cin >> (s);
#define rz resize
#define vvi vector<vector<int>>
#define sz(s) s.size()
#define mod 1000000007
#define ff first
#define ss second
#define inf 10e15
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define mii map<int,int>
#define vl(n) cout << n << "\n"
#define vs(n) cout << n << " "
#define el cout<<"\n"
#define rmin(a,b) (a=min((a),(b)))
#define rmax(a,b) (a=max((a),(b)))
#define UB upper_bound
#define LB lower_bound
#define vn(n) cout << n
#define dsc greater<int>()
#define ps(x,y)  fixed<<setprecision(y)<<x
#define R return
#define B break
#define C continue
#define YC cout<<"YES"<<"\n"
#define YS cout<<"Yes"<<"\n"
#define NC cout<<"NO"<<"\n"
#define fv(a) for(auto v:(a))
#define NS cout<<"No"<<"\n"
#define lcm(a,b) (a/__gcd(a,b))*b
#define pa(a) for(auto e:a)cout<<e<<" "
const int N = 1e5 + 5;
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int kx[8] = { -1, 1, 0, 0, -1, -1, 1, 1};
int ky[8] = {0, 0, -1, 1, -1, 1, -1, 1};

#ifndef ONLINE_JUDGE
#define pra(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define prm(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S, class T>ostream &operator<<(ostream &os, const pair<S, T> &p) {return os << "(" << p.first << "," << p.second << ")";}
template<class T>ostream &operator<<(ostream &os, const vector<T> &p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const set<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>ostream &operator<<(ostream &os, const multiset<T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class S, class T>ostream &operator<<(ostream &os, const map<S, T>&p) {os << "["; for (auto&it : p)os << it << " "; return os << "]";}
template<class T>void dbs(string str, T t) {cerr << str << ":" << t << "\n";}
template<class T, class...S>void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << ":" << t << ","; dbs(str.substr(idx + 1), s...);}
#else
#define pr(...){}
#define pra(a,n){}
#define prm(mat,row,col){}
#endif
 
bool check(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), i, sum = accumulate(nums.begin(), nums.end(), 0);
    if(n <= 1 || sum % 2) return false;
    sum /= 2;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for(auto x : nums)
        for(i=sum; i>=0; i--)
            if(i - x >= 0 && dp[i - x])
                dp[i] = true;
    return dp[sum];
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
	/*
		People have explained the math approach to solving problem C but the intuition behind the solution was not clear. Specifically, when all numbers are even, keep dividing them until you get an odd — and that's the one to remove.

		I finally get the intuition behind this. We need to look at it not from a numeric standpoint, but from a bit standpoint. If a given array is balanced (i.e. it can be partitioned into 2 subsets), then rather than look at the smallest number, we need to look at the number with the smallest bit set. This is because, in a balanced array, this bit (i.e. the least significant) is set an even number of times. Removing any number with this bit breaks the balance (making the number of available bits odd) such that you can't evenly split it between two groups.
		
		Consider two examples:
		
		1) [1 2 3 6]
		
		This is currently balanced as you can can split it into [1 2 3] and [6]
		
		The lowest bit is 1 and it's set in two numbers 1 and 3. Removing any one makes the array unbalanced
		
		2) [6 6 4 4 4]
		
		This is currently balanced as you can can split it into [6 6] and [4 4 4]
		
		In binary notation, 6 = 110 (== 4 + 2), and 4 = 100
		
		Note that if you removed 4 (the smallest number), it would still be balanced as you could split it into [6 4] and [6 4]
		
		However, if you remove a 6, there's no way to partition it in a balanced manner. This is because getting rid of the 6 gets rid of the least significant bit (i.e. the second bit which has a value of 2) and there's an odd number of those bits remaining -- and no smaller bits can add up to replace it.
	*/
		int n, i, j;
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> ind;
	for(i=0; i<n; i++) {
		cin >> a[i];
		int x = a[i] & ~(a[i] - 1);
		ind.push_back({x, i});
	}
	if(!check(a)) {
		cout << 0 << endl;
		return;
	}
	sort(ind.begin(), ind.end());
	cout << 1 << endl;
	cout << ind[0].second + 1 << endl;

}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    // cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}