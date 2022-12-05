//Problem Link : 
// Topic : Segment Tree, Divide and Conquer, Greedy.
#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define int long long int
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
// template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
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
int n;
vi a;
struct NODE{
    // Can be modified according to the question.
    int ans;int ind;
    // Setting the value for default value.
    NODE():ans(inf),ind(inf){}
};
NODE tree[4*N];
NODE combine(NODE a,NODE b){
    // Can be modified according to the question.
    NODE c;
    if(a.ans>b.ans){
        swap(a,b);
    }
    c.ans=a.ans;
    c.ind=a.ind;
    if(a.ind==inf){
        c.ind=b.ind;
    }
    return c;
}
void build(int node,int start,int end){
    if(start==end){
        // Can be changed according to the question
        tree[node].ans=a[start];
        tree[node].ind=start;
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=combine(tree[2*node],tree[2*node+1]);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind,int val){
    if(start==end){
        // Can be changed according to the question
        tree[node].ans=val;
        tree[node].ind=start;
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind,val);
    }
    else{
        update1(2*node,start,mid,ind,val);
    }
    tree[node]=combine(tree[2*node],tree[2*node+1]);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r);
    NODE rq=query(2*node+1,mid+1,end,l,r);
    return combine(lq,rq);
}
int rec(int st,int en,int cst){
    int ans=0;
    if(st>en){
        return 0;
    }
    if(st==en){
        if(a[st]==inf){
            return 0;
        }
        else{
            return a[st]-cst;
        }
    }
    int ind=query(1,0,n-1,st,en).ind;
    // cout<<"Index is "<<ind<<" "<<a[ind]<<endl;
    ans=a[ind]-cst;
    if(a[ind]==0){
        ans=0;
    }
    ans+=rec(st,ind-1,a[ind]);
    ans+=rec(ind+1,en,a[ind]);
    // cout<<"Ans of range "<<st<<" "<<en<<" "<<cst<<" is "<<ans<<endl;
    return ans;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
    ...|6|5|...0....|5|..0....5....7....9...0...9....11.......0....13.....
    ...|6|5|...
    ...|1|0|...
            ... ->one problem
    ...|1       ->other problem
    (l,r) mein minimum chahiye.
    Us se solve with it's index. Segment Tree, we will keep on dividing until the problem is solved,recursively.
    */
    /*
        Sample 1:
        DIff array :
        1 2 3 4 5 6 7 8 2 4 9
        8 2 inf 4 2 inf' inf inf 1 inf inf
        8 + 4 + 1 ->13 but accrding to our logic answer is 10 :\
        

        Case : Middle index of odd lenght array.
        ...> ya to mid-1 mein inf, ya mid+1 mein, ya dono mein inf hoga.Means isko alag se solve krna hi hoga.
        Jaha inf hai, udhar se divide krna hai.
        What if hm agar usko 0 krde to,



    */
    
    cin>>n;
    for(int i=0;i<=4*n;i++){
        tree[i].ans=inf;
        tree[i].ind=inf;
    }
    a.clear();
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int diff[n];
    for(int i=0;i<n;i++){
        if(a[i]>=a[n-1-i]){
            diff[i]=0;
        }
        else{
            diff[i]=a[n-1-i]-a[i];
        }
    }
    for(int i=0;i<n;i++){
        a[i]=diff[i];
    }
    build(1,0,n-1);
    int res=rec(0,n-1,0);
    cout<<res<<endl;


    




}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    cin >> t;
    fl(i, 1, t + 1) {
        // cout<<"Here"<<endl;
        solve();

    }
    return 0;
}