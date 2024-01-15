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
int cal(int c1,int c2,int c3){
	int val=(c1-c2)*(c1-c2);
	val+=((c1-c3)*(c1-c3));
	val+=((c2-c3)*(c2-c3));
	return val;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
	e3(r,g,b);
	av(a1,r);av(a2,g);av(a3,b);
	pr(a1);pr(a2);pr(a3);
	sort(all(a1));sort(all(a2));sort(all(a3));
	int val=LLONG_MAX;
	fl(i,0,r){
		int c1=a1[i];
		auto it1=LB(all(a2),c1);
		if(it1==a2.end()){
			it1--;
		}
		int c2=*it1;
		auto it2=LB(all(a3),c1);
		if(it2==a3.end()){
			it2--;
		}
		int c3=*it2;
		val=min(val,cal(c1,c2,c3));
		int c21=c2;
		if(it1!=a2.begin()){
			it1--;
		}
		c21=*it1;
		int c31=c3;
		if(it2!=a3.begin()){
			it2--;
		}
		c31=*it2;
		pr(c1,c2,c3,c21,c31);
		val=min(val,cal(c1,c2,c31));
		val=min(val,cal(c1,c21,c3));
		val=min(val,cal(c1,c21,c31));
	}
	fl(i,0,g){
		int c1=a2[i];
		auto it1=LB(all(a1),c1);
		if(it1==a1.end()){
			it1--;
		}
		int c2=*it1;
		auto it2=LB(all(a3),c1);
		if(it2==a3.end()){
			it2--;
		}
		int c3=*it2;
		val=min(val,cal(c1,c2,c3));
		int c21=c2;
		if(it1!=a1.begin()){
			it1--;
		}
		c21=*it1;
		int c31=c3;
		if(it2!=a3.begin()){
			it2--;
		}
		c31=*it2;
		pr(c1,c2,c3,c21,c31);
		val=min(val,cal(c1,c2,c31));
		val=min(val,cal(c1,c21,c3));
		val=min(val,cal(c1,c21,c31));		
	}
	fl(i,0,b){
		int c1=a3[i];
		auto it1=LB(all(a2),c1);
		if(it1==a2.end()){
			it1--;
		}
		int c2=*it1;
		auto it2=LB(all(a1),c1);
		if(it2==a1.end()){
			it2--;
		}
		int c3=*it2;
		val=min(val,cal(c1,c2,c3));
		int c21=c2;
		if(it1!=a2.begin()){
			it1--;
		}
		c21=*it1;
		int c31=c3;
		if(it2!=a1.begin()){
			it2--;
		}
		c31=*it2;
		pr(c1,c2,c3,c21,c31);
		val=min(val,cal(c1,c2,c31));
		val=min(val,cal(c1,c21,c3));
		val=min(val,cal(c1,c21,c31));
	}
	cout<<val<<endl;
	
	
}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}