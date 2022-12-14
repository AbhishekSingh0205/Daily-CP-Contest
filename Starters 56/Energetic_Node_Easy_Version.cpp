/*
    As there are going to be atmax 4e4 qrys means at max there can be 4e4 qrys for each x.
    At max there can be 4e4 summation of qrys.
    

    Now we will dfs from root node, at each [src] node, we will caluculate for all the [qrys] whose [x] is [src].

    This will take at max (N + Q)
    
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
#define int long long

// Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
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
const int N = 4e4 + 5;
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

struct query{
    int id;
    int t,k;
   
};
ordered_set st; 
void dfs(int i,vector<int> &vis,vector<vector<int>> & adj,vector<int> &ene,vector<query>  qr[],vector<int> &ans){
    vis[i]=1;
    if(ene[i]){
    st.insert({ene[i],i});
    }
    for(auto &x:qr[i]){
        int id = x.id;
        int t = x.t;
        int k = x.k;
        if(st.size()<t){
            ans[id]=-1;continue;
        }
        auto it = st.find_by_order(st.size()-t);
        int val = it->first;
    //     cout<<val<<endl;
    //    cout<<k<<endl;
        int low = 1;
        int high = sqrt(4e18/val);
        
        while(low<=high){
            int mid = (low + high)/2;
           // cout<<low<<" "<<mid<<" "<<high<<endl;
            if(val*(mid)*(mid+1) >= 2*k){
                ans[id]=mid;
              //  cout<<mid<<" \n";
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
    }
    for(auto &child:adj[i]){
        if(vis[child]==0){
            dfs(child,vis,adj,ene,qr,ans);
        }
    }
    if(ene[i]){
        st.erase({ene[i],i});
    }
    
}
int32_t main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){cin>>a[i];}
    int l,r;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        cin>>l>>r;
        l--;
        r--;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    vector<int> ene(n,0);
    for(int i=0;i<n;i++){
             ene[i]=a[i];
        for(auto &child:adj[i]){
            if(a[child]){ene[i]++;}
        }
    }
    int q;
    cin>>q;
    vector<int> ans(q);
    vector<query> qr[n];
    // q[x] -> x kaunse qrys
    int i=0;
    while(q--){
        int x,k,t;
        cin>>x>>t>>k;
        x--;
        query y;
        y.id = i;
        y.k = k;
        y.t = t;
        qr[x].push_back(y);
        i++;
    }
    vector<int> vis(n,0);
    dfs(0,vis,adj,ene,qr,ans);
    for(auto &x:ans){
        cout<<x<<"\n";
    }
    cout<<"\n";
    
}