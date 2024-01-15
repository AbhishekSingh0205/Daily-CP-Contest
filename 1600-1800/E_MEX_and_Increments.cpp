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
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
        Appraoch : 
        Once answer is not possible for any x, then it will not be possible for all i>x.
        Now calculating the minimum number of operations. 
        We will mantain one variable reqd=0, which will tell number of operations required to such that all the numbers from 0 to i are present atleast 1 times.

        We will also store the remaining elements, from which we will be making the new elements.

        How would we do that?
        {0,1,2,3,.....,i-1}
        reqd = j, Remaining elements => (. . . . . . . .)
        Current index, at which I am present, 
    */
    e1(n);
    multiset<int>st;
    av(a,n);sort(all(a));int currId=0;
    int reqd=0;
    vi arr;
    bool ans=false;
    map<int,int>m;
    fl(i,0,n){
        m[a[i]]++;
    }
    if(a[0]>0){
        ans=1;
    }
    cout<<m[0]<<" ";
    if(ans==0){
        currId++;arr.pb(0);
        while(currId<n && a[currId]==0){
            st.insert(a[currId]);currId++;
        }
    }
    pr(st);
    for(int i=1;i<=n;i++){
        if(ans){
            cout<<-1<<" ";C;
        }
        else{
        	if(arr[i-1]==i-1){
            	cout<<reqd+m[i]<<" ";
            }
        }
        if(currId<n){
            if(a[currId]==i){
                arr.pb(i);
                currId++;
            }
            else if(st.size()){
                reqd+=(i-*st.rbegin());
                st.erase(st.find(*st.rbegin()));
                arr.pb(i);
            }
            else{
                ans=1;
            }
        }
        else{
        	if(st.size()){
	            reqd+=(i-*st.rbegin());
	            st.erase(st.find(*st.rbegin()));
	            arr.pb(i);
        	}
        	else{
        		ans=1;
        	}
        }
        while(currId<n && a[currId]==i){
            st.insert(a[currId]);
            currId++;
        }
    }
    cout<<endl;

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