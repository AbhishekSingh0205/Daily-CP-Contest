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
const int N = 2e5 + 5;
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
vi a;

int tt=0;
struct NODE{
    // Can be modified according to the question.
    int val,ind;
    // Setting the value for default value.
    NODE(){
    	val=0,ind=-1;
    }
};

// Segment Tree to find the nearest 
NODE segTree[4*N];
NODE combine(NODE a,NODE b){
    // Can be modified according to the question.
    NODE c;
    c.val=max(a.val,b.val);
    if(a.val>=1){
    	c.ind=a.ind;
    }
    else{
    	c.ind=b.ind;
    }
    return c;
}
void build(int node,int start,int end){
    if(start==end){
        // Can be changed according to the question
        segTree[node].val=a[start];
        if(segTree[node].val==0){
        	segTree[node].ind=-1;
        }
        else{
        	segTree[node].ind=start;
        }
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind){
    if(start==end){
        // Can be changed according to the question
        segTree[node].val--;
        if(segTree[node].val==0){
        	segTree[node].ind=-1;
        }
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind);
    }
    else{
        update1(2*node,start,mid,ind);
    }
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return segTree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r);
    NODE rq=query(2*node+1,mid+1,end,l,r);
    return combine(lq,rq);
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
	/*
		Logic : 
			Let's take the example when they are alternate and single.
			Case 1 : N length : 010101010, ->It will take maximum ceil(N/2) operations
					To have this we will keep removing one element from back.
			
			
			
			Everytime atleast one segment is going to be erased.
			Why not try to not down the number of segments.
			We will evaluate the length the segments.
			
			Let's we are current ith segment then if the length of this segment is >1,
			then we will delete the element from this segment then remove the prefix.
			
			Other wise we will find on nearest right if there is any segment with length greater than 1.
			And we will remove the element from that segment.
			
			Else if we can't find any segment then we will take Case 1 and add the answer.
	*/	
	tt++;
	e1(n);es(s);
	a.resize(0); // Prefix array.
	char c=s[0];
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]==c) cnt++;
		else{
			a.pb(cnt);
			c=s[i];
			cnt=1;
		}
	}
	a.pb(cnt);n=a.size();
	cnt=0;
	pr(a);
	fl(i,0,n){
		a[i]--;
	}
	for(int i=0;i<4*n;i++){
		segTree[i].val=0,segTree[i].ind=-1;
	}
	build(1,0,n-1);
	fl(i,0,n){
		if(a[i]>=1){
			cnt++;C;
		}
		int id=query(1,0,n-1,i+1,n-1).ind;
		if(id==-1){
			cnt+=((n-i)/2);
			if((n-i)%2){
				cnt++;
			}
			B;
		}
		else{
			cnt++;
			a[id]--;
			update1(1,0,n-1,id);
		}
	}
	if(tt==21){
		cout<<s<<"::";
	}
	cout<<cnt<<endl;
	
	
	
}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    cin >> t;
    tt=0;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}