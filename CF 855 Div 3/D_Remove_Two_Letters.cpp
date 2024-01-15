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
#define mod 2147483647
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
bool ispal(string s){
    int lo=0,hi=s.size()-1;
    bool is=true;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-1-i]){
            is=false;
        }
    }
    return is;
}
int gcdExtended(int a, int b, int* x, int* y);
 
// Function to find modulo inverse of a
int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    int res = (x % M + M) % M;
    return res;
}
int gcdExtended(int a, int b, int* x, int* y)
{
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e1(n);es(s);
    int pref[n];memset(pref,0,sizeof pref);
    int pref2[n];memset(pref,0,sizeof pref);
    int mod2=1000000007;
    int p2=31,curr2=31;
    int suff[n];memset(suff,0,sizeof suff);
    int p=37;
    int curr=37;
    fl(i,0,n){
        pref[i]=(s[i]-'a'+1)*curr;
        pref[i]%=mod;
        if(i){
            pref[i]+=pref[i-1];
        }
        pref[i]%=mod;pref[i]+=mod;pref[i]%=mod;
        curr*=p;
        curr%=mod;curr+=mod;curr%=mod;
    }
    fl(i,0,n){
        pref2[i]=(s[i]-'a'+1)*curr2;
        pref2[i]%=mod2;
        if(i){
            pref2[i]+=pref2[i-1];
        }
        pref2[i]%=mod2;pref2[i]+=mod2;pref2[i]%=mod2;
        curr2*=p2;
        curr2%=mod2;curr2+=mod2;curr2%=mod2;
    }
    // pra(pref2,n);
    set<pair<int,int>>st;
    fl(i,2,n){
        int sum=pref[n-1];
        sum-=pref[i-1];
        sum%=mod;sum+=mod;sum%=mod;
        sum*=modInverse(p*p,mod);
        if(i-2){
            sum+=pref[i-3];
        }
        sum%=mod;sum+=mod;sum%=mod;
        int sum2=pref2[n-1];
        sum2-=pref2[i-1];
        sum2%=mod2;sum2+=mod2;sum2%=mod2;
        sum2*=modInverse(p2*p2,mod2);
        if(i-2){
            sum2+=pref2[i-3];
        }
        sum2%=mod2;sum2+=mod2;sum2%=mod2;
        st.insert({sum,sum2});

    }
    int sum=pref[n-3];
    sum%=mod;sum+=mod;sum%=mod;
    int sum2=pref2[n-3];
    sum2%=mod2;sum2+=mod2;sum2%=mod2;
    st.insert({sum,sum2});
    // pr(st);
    cout<<st.size()<<endl;
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