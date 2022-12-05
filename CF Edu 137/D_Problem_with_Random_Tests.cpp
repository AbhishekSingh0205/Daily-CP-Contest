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
    // Kaam krna apna BC kya comment padh rha hai
    /* Idea : Find the first 1 from which we can make the answer, and then will try to make upcoming 0 to 1, by taking that number.

    Ex : 00010001010               01234567
    So My answer will be atleast : 10001010, Now will be trying to 1st,2nd,3rd,5th and 7th index zero to 1, with priority order as {1st,2nd,3rd,5th and 7th}.
    */
    e1(n);es(s);
    int id=-1;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            id=i;
        }
    }
    if(id==-1){
        cout<<0<<endl;R;
    }
    int len=n-id;
    int tId=id;
    string ans(len,'0');
    for(int i=0;i<len;i++){
        ans[i]=s[tId];
        tId++;
    }
    pr(ans);
    int diff=n-len;
    vi pos1;
    for(int i=0;i<len;i++){
        if(ans[i]=='0'){
            B;
        }
        else{
            pos1.pb(i);
        }
    }
    vi arr;
    for(int i=0;i<len;i++){
        if(ans[i]=='0'){
            arr.pb(i);
        }
    }
    if(arr.size()==0){
        cout<<ans<<endl;
    }
    pr(pos1);
    pr(arr);
    int cnt=1,idM=0;
    string res=ans;
    for(auto v:pos1){
        string tmp=ans;
        int prev=v;
        int pId=arr[0];
        tmp[pId]='1';
        for(int i=1;i<arr.size();i++){
            int ind=prev+arr[i]-pId;
            pr(ind);
            if(ans[ind]=='1'){
                tmp[arr[i]]='1';
            }
            pId=arr[i];
            prev=ind;
        }
        pr(tmp);
        res=max(res,tmp);
    }
    cout<<res<<endl;
     

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