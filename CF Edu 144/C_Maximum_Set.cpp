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
    /*
        First of all let's calcualate the max length. Notice that it can be achieved in a such way: x 2x 4x 8x and so on. So it can be easily calculated in log(n) time. Now lets find out how all sequences of this length look like, for example for l=4, r=100:

        4 8 16 32 64 -> *2 *2 *2 *2
        4 8 16 32 96 -> *2 *2 *2 *3
        4 8 16 48 96 -> *2 *2 *3 *2
        4 8 24 48 96 -> *2 *3 *2 *2
        4 12 24 48 96 -> *3 *2 *2 *2
        5 10 20 40 80 -> *2 *2 *2 *2
        6 12 24 48 96 -> *2 *2 *2 *2
        So its not optimal to perform any kind of operation except *2 and *3 in this sequence, because if you do *4, you can replace it with *2 *2 and get sequence with higher lenght. Also we dont care about in what order they were performed since multiplication is a communicative operation. Now we can fix number of *3 operations, calculate total number of seq with this count of *3 operation: C(numberof(*3), maxsize) and then find from what numbers they can start.
    */
    e2(l,r);
    int cnt=0,tmp=l;
    while(tmp<=r){
        tmp*=2;cnt++;
    }
    if(cnt==1){
        cout<<1<<" "<<r-l+1<<endl;R;
    }
    int curr=3;tmp=0;
    fl(i,0,cnt-2){
        curr*=2;
    }
    int res=0;
    int lo=l,hi=r,ans=l-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(mid*curr<=r){
            ans=mid;lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    if(ans>=l){
        res+=(ans-l+1)*(cnt-1);
    }
    lo=l,hi=r,ans=l-1;curr/=3;curr*=2;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(mid*curr<=r){
            ans=mid;lo=mid+1;
        }
        else hi=mid-1;
    }   
    if(ans>=l){
        res+=(ans-l+1);
    }
    cout<<cnt<<" ";
    cout<<res%mod<<endl;

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