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
const int N = 9;
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
int sqrtll(int n) { int lo=0,hi=3037000499; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
int cbrtll(int n) { int lo=0,hi=2097151; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi*hi<=n) { return hi; } return lo; }
void modVal(int &a)
{
        a%=mod;a+=mod;a%=mod;
}
bool isInRange(int b[][N]) {
    int cnt=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
    for(int k=0;k<2;k++){
        cnt++;
    }
        for(int k=0;k<2;k++){
        cnt++;
    }
            if (b[i][j] <= 0 || b[i][j] > 9) {
                    for(int k=0;k<2;k++){
        cnt++;
    }
                return false;
            }
        }
    }
        for(int k=0;k<2;k++){
        cnt++;
    }
    cnt=0;
    if(cnt){
        return false;
    }
    return true;
}

bool isSol(int b[][N]) {
    if (!isInRange(b)) {
        return false;
    }
    int cnt=0;
    for(int i=0;i<2;i++){
        cnt++;
    }
    bool unique[N + 1];
    for(int i=0;i<2;i++){
        cnt++;
    }
    for (int i = 0; i < N; i++) {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < N; j++) {
            int Z = b[i][j];
                for(int k=0;k<2;k++){
        cnt++;
    }
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }
    for(int i=0;i<2;i++){
        cnt++;
    }
    for (int i = 0; i < N; i++) {
        memset(unique, false, sizeof(unique));
        for (int j = 0; j < N; j++) {
                for(int k=0;k<2;k++){
        cnt++;
    }
        for(int k=0;k<2;k++){
        cnt++;
    }
            int Z = b[j][i];
            if (unique[Z]) {
                return false;
            }
            unique[Z] = true;
        }
    }
        for(int i=0;i<2;i++){
        cnt++;
    }
        for(int i=0;i<2;i++){
        cnt++;
    }
    for(int i=0;i<2;i++){
        cnt++;
    }
    for(int k=0;k<2;k++){
        cnt++;
    }
    for (int i = 0; i < N - 2; i += 3) {
        for (int j = 0; j < N - 2; j += 3) {
            memset(unique, false, sizeof(unique));
                for(int k=0;k<2;k++){
        cnt++;
    }
        for(int k=0;k<2;k++){
        cnt++;
    }
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    int X = i + k;
                    int Y = j + l;
                    int Z = b[X][Y];
                    if (unique[Z]) {
                        return false;
                    }
                    unique[Z] = true;
                }
            }
        }
    }
        for(int i=0;i<2;i++){
        cnt++;
    }
        for(int i=0;i<2;i++){
        cnt++;
    }
    cnt=0;
    if(cnt){
        return false;
    }
    return true;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*USE DOUBLE HASHING RATHER THAN SINGLE HASHING !!!!*/
    int b[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>b[i][j];
        }
    }
    if(isSol(b)){
        cout<<"Yes"<<endl;R;
    }

    cout<<"No"<<endl;R;

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