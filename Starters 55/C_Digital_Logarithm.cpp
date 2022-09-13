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
int cntD(int n){
    int cnt=0;
    while(n){
        cnt++;n/=10;
    }
    return cnt;
}
void solve()
{
    // 2 operation mein 1
    e1(n);av(a,n);av(b,n);
    multiset<int>sa,sb;
    int a1=0,b1=0;
    fl(i,0,n)
    {
        if(a[i]!=1) 
        sa.insert(a[i]);
        else a1++;
    }
    fl(i,0,n) {
        if(b[i]!=1)
        sb.insert(b[i]);
        else b1++;
    }
    // Removing same elements
    auto it=sa.begin();
    while(it!=sa.end()){
        if(sb.find(*it)!=sb.end()){
            sb.erase(sb.find(*it));
            auto oldIt=it;it++;
            sa.erase(oldIt);
        }
        else{
            it++;
        }
    }
    // Removing digits same
    it=sa.begin();
    int cnt=0;
    while(it!=sa.end()){
        auto zt=sb.find(cntD(*it));
        if(zt!=sb.end()){
            sb.erase(zt);
            auto oldIt=it;it++;
            sa.erase(oldIt);
            cnt++;
        }
        else{
            it++;
        }
    }
    it=sb.begin();
    while(it!=sb.end()){
        auto zt=sa.find(cntD(*it));
        if(zt!=sa.end()){
            sa.erase(zt);
            auto oldIt=it;it++;
            sb.erase(oldIt);
            cnt++;
        }
        else{
            it++;
        }
    }
    // removed same digits, same numbers
    int arr[9];memset(arr,0,sizeof arr);
    for(auto v:sa){
        int dig=cntD(v);
        arr[dig-1]++;
    }
    int brr[9];memset(brr,0,sizeof brr);
    for(auto v:sb){
        int dig=cntD(v);
        brr[dig-1]++;
    }
    for(int i=1;i<9;i++){
        int mnm=min(arr[i],brr[i]);
        cnt+=(2*mnm);
        arr[i]-=mnm;
        brr[i]-=mnm;
    }
    int rem[9];memset(rem,0,sizeof rem);
    int i=1;
    while(a1 && i<9){
        int mnm=min(a1,brr[i]);
        a1-=mnm;brr[i]-=mnm;
        cnt+=(2*mnm);
        i++;
    }  
    i=1;
    while(b1 && i<9){
        int mnm=min(b1,arr[i]);
        b1-=mnm;arr[i]-=mnm;
        cnt+=(2*mnm);
        i++;
    }
    
    i=1;
    int sum=0;
    while(i<9){
        sum+=arr[i];
        sum+=brr[i];
        i++;
    }
    cnt+=(2*sum);
    cnt+=arr[0];
    cnt+=brr[0];
    cout<<cnt<<endl;



}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t = 1;
    cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}
/*

*/