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
void solve()
{
	
	/*
	N stones
	Alice removes : Multiple of A
	Bob   removes : Multiple of B
	1 : Bob
	2 : Alice
	3 : Bob
	4 : Alice
	
	
	
	->N=6 A=2,B=2 : Always alice(A==B)
	
	->N=38 A=7,B=3 : (A>B)
	    ::<7 : BOB
	    ::8,9,10,11,12,13  : BOB---10,11,12,13 ALICE---8,9
	    ::15,16,17,18,19,20: BOB---
	    ROUGH FOR 15: (15-14,A) (1,B X) ALICE WINS
	    ROUGH FOR 16: (16-14,A) (2,B X) ALICE WINS
	    ROUGH FOR 17: (17-7 ,A) (10-9,B) (1,A X) BOB WINS
	    ROUNG FOR 18: (18-7, A) (11-9,B) (2,A X) BOB WINS
	    ROUGH FOR 19: (19-7, A) (12-12,B)(0,A X) BOB WINS
	    ROUGH FOR 20: (20-7,A)  (13-12,B) BOB WINS 
	    ::36,37,38  : BOB WINS FOR ONLY 38
	
	    :::::::::::RESULT::::::::::
	    Means Alice wins for all factors for A and (Factors of A + (B-1))
	    Bob wins for the numbers < A and (>=(Factors of A + B) until the next factor)
	    Edge Case : Check for the numbers which are at the last set like (36,37,38)
	              : and also we have to leave first (a-1) numbers as bo is going to  win in that set.
	              factA=n/a;
	              factA=max(factA-1,0ll)
	              : so (factA)+(factA*(b-1))+min(b-1,n-factA*(a))-(b-1)
	
	->N=38, A=3,B=7
	    ::<3 : BOB WINS
	    ::4,5: ALICE WINS
	    ::7,8: ALICE WINS
	    :::::::::::RESULT::::::::::
	    Alice wins for all the numbers except numbers<A
	
	
	
	
	Remember ***THE MOST IMPORTANT EDGE CASE*** : If a>n then answer is 0

	*/
	e1(n);
	e2(a,b);
	int bobWins=a-1;
	int factA=0;
	int temp=n;
	factA=n/a;
	int aliceWins=factA;
	if(a>n){
		cout<<0<<endl;R;
	}
	if(a==b){
		cout<<max(0ll,n-(bobWins))<<endl;R;
	}
	else if(a>b){
		pr(factA);
		factA=max(0ll,factA-1);
		aliceWins=max(0ll,factA);
		pr(factA);
		aliceWins+=(factA*(b-1));
		aliceWins+=min(n-(n/a)*a,b-1);
		cout<<max(0ll,aliceWins-(b-1)+b)<<endl;
	}
	else{
		aliceWins=n-bobWins;
		cout<<max(0ll,aliceWins)<<endl;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1;
	// cin >> t;
	fl(i, 1, t + 1) {
		solve();
	}
	return 0;
}