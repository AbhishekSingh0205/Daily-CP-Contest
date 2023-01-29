//Problem Link : https://codeforces.com/problemset/problem/1735/D
// Date : 10th January 2022
// Problem Count =1 
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
#define mod 2
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


bool good(int a,int b){
	 int num=0;
	 int curr=1;
	 while(a||b){
	 	if(a%3 && b%3 && (a%3==b%3)){
			return false;
		}
	 	a/=3;b/=3;
	 }
	 return true;
}
void solve()
{
	/*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
	/*
		Topic : Simple Combontrics
		My Approach : 
		Hint : For every two cards, there is always a single card (if it is present) that forms a set with them.
				[1] That means that two sets can share at most one card.
			We will calculate for each card that how many pair of cards have that card as required 
			to form a set.

			Now we will iterate for each card and we need to take only two pair of cards for that card in
			common.
	*/
	e2(n,k);
	map<int,int>m;
	vi a;
	fl(i,0,n){
		int num=0;
		int curr=1;
		fl(j,0,k){
			e1(x);
			num+=(x*curr);
			curr*=3;
		}
		a.pb(num);
	}
	fl(i,0,n){
		m[a[i]]=0;
	}
	fl(i,0,n){
		fl(j,i+1,n){
			if(good(a[i],a[j])){
				int n1=a[i],n2=a[j];
				int curr=1;
				int num=0;
				while(n1||n2){
					if(n1%3||n2%3){
						int rem=n1%3+n2%3;
						num+=(curr*(3-rem));
					}
					curr*=3;
					n1/=3;n2/=3;
				}
				if(m.find(num)!=m.end()){
					m[num]++;
				}
			}
		}
	}
	int ans=0;
	for(auto v:m){
		ans+=(v.ss*(v.ss-1))/2;
	}
	cout<<ans<<endl;
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