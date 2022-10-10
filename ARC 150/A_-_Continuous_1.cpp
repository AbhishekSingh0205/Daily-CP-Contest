
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
    e2(n,k);es(s);    
    int fst=-1,lst=-1;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            fst=i;B;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            lst=i;B;
        }
    }
    // Atleast two ones.
    if(fst!=lst){
        for(int i=fst;i<lst;i++){
            if(s[i]=='0'){
                cout<<"No"<<endl;R;
            }
        }
        if(lst-fst+1==k){
            cout<<"Yes"<<endl;R;
        }
        if(lst-fst+1>k){
            cout<<"No"<<endl;R;
        }
        // int cnt=0;
        int prev=0;
        int curr=fst-1;
        while(curr>=0 && s[curr]=='?'){
            prev++;
            curr--;
        }
        curr=lst+1;
        int next=0;
        while(curr<n && s[curr]=='?'){
            next++;
            curr++;
        }
        int temp=lst-fst+1;
        if(temp+next+prev==k){
            cout<<"Yes"<<endl;R;
        }
        else if((next==0||prev==0) && temp+next+prev>=k){
            cout<<"Yes"<<endl;R;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    // Only one 1.
    else if(fst==lst && fst!=-1){
        int cntp=0;
        if(k==1){
            cout<<"Yes"<<endl;R;
        }
        int curr=fst-1;
        while(curr>=0 && s[curr]=='?'){
            cntp++;
            curr--;
        }
        int prev=cntp;
        int next=0;
        curr=fst+1;
        while(curr<n && s[curr]=='?'){
            next++;
            curr++;
        }
        if(next+prev+1==k){
            cout<<"Yes"<<endl;R;
        }
        else if((next==0||prev==0) && next+prev+1>=k){
            cout<<"Yes"<<endl;R;
        }
        else cout<<"No"<<endl;R;
    }
    // No one.
    else{
        int a[n];
        int cntk=0;
        memset(a,0,sizeof a);
        fl(i,0,n){
            if(s[i]=='?'){
                a[i]++;
            }
            if(i && a[i]){
                a[i]+=a[i-1];
            }
            if(a[i]>=k){
                cntk++;
            }
        }
        if(cntk==1){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
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
