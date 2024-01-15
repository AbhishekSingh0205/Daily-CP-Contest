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
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
	e1(n);e1(q);es(s);
	/*
		We will maintain two array one for prefix and suffix.
		Each array will have Current Value, maxm value, minm value till that.
	
		Suffix array will contain two more things. Maximum increase from
		the current index, and minimum decrease from the current index.
	*/
	int pf[n][3];memset(pf,0,sizeof pf);
	int sf[n][3];memset(sf,0,sizeof sf);
	fl(i,0,n){
		if(i){
			fl(j,0,3){
				pf[i][j]=pf[i-1][j];
			}
		}
		if(s[i]=='+'){
			pf[i][0]++;
		}
		else{
			pf[i][0]--;
		}
		pf[i][1]=max({pf[i][0],pf[i][1]});
		pf[i][2]=min({pf[i][0],pf[i][2]});
	}
	for(int i=n-1;i>=0;i--){
		if(i!=n-1){
			fl(j,0,3){
				sf[i][j]=sf[i+1][j];
			}
		}
		if(s[i]=='+'){
			sf[i][0]++;
		}
		else{
			sf[i][0]--;
		}
		sf[i][1]=max(sf[i][0],sf[i][1]);
		sf[i][2]=min(sf[i][0],sf[i][2]);
	}
	int sf2[n][3];memset(sf2,0,sizeof sf2);
	for(int i=0;i<n;i++){
		sf2[i][0]=sf[i][0];
		sf2[i][1]=max(sf2[i][0],0ll);
		sf2[i][2]=min(sf2[i][0],0ll);
	}
	// sf2[i][1] = Current Maximum
	// sf2[i][1] = max(sf2[i][0],sf2[i][1]+sf2[i][0]);
	// sf2[i][2] = min(sf2[i][0],sf2[i][2]+sf2[i][0]);
	// for(int i=0;i<n;i++){
		// cerr<<sf2[i][0]<<" ";
	// }
	// cerr<<endl;
		// fl(i,0,n){
		// pr(i,sf2[i][0],sf2[i][1],sf2[i][2]);
	// }
	// pr("\n");
	for(int i=n-1;i>=0;i--){
		if(i!=n-1){
			int prvMx=sf2[i+1][1],prvMn=sf2[i+1][2];
			prvMx=max(prvMx,0ll);prvMn=min(prvMn,0ll);
			if(s[i]=='+'){
				prvMx++;
				prvMn++;
				sf2[i][1]=max({sf2[i][0],1ll,prvMx});
				sf2[i][2]=min({sf2[i][0],0ll,prvMn});
			}
			else{
				prvMn--;prvMx--;
				sf2[i][1]=max({sf2[i][0],0ll,prvMx});
				sf2[i][2]=min({sf2[i][0],-1ll,prvMn});
			}
		}
	}
	// fl(i,0,n){
		// pr(i,sf2[i][0],sf2[i][1],sf2[i][2]);
	// }
	// pr("\n");
	fl(i,0,q){
		e2(l,r);l-=2;
		// pr(l,r);
		int mxm=0,mnm=0;
		int val=0;
		if(l>=0){
			mxm=max(mxm,pf[l][1]);
			mnm=min(mnm,pf[l][2]);
			val=pf[l][0];
			// pr(val);
		}
		// pr(mxm,mnm);
		if(r<n){
			// pr(sf2[r][0],sf2[r][1],sf2[r][2]);
			mxm=max(mxm,val+sf2[r][1]);
			mnm=min(mnm,val+sf2[r][2]);
		}
		int res=mxm+abs(mnm)+1;
		cout<<res<<endl;
		
	}
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