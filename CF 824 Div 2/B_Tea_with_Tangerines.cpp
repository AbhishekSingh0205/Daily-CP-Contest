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
// int parent[101];
// int size[101];
// void make_set(int v) {
//     parent[v] = v;
//     size[v] = 1;
// }

// void union_sets(int a, int b) {
//     a = find_set(a);
//     b = find_set(b);
//     if (a != b) {
//         if (size[a] < size[b])
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }

int factorial(int n){
    int ans=1;
    fl(i,1,n+1){
        ans=(ans%mod)*(i%mod);
        ans%=mod;
    }
    return ans;
}
int res[111][101][101][3];
void init(){
    fl(i,0,111){
        fl(j,0,101){
            fl(k,0,101){
                fl(m,0,3){
                    res[i][j][k][m]=0;
                }
            }
        }
    }
}
void solve()
{
    e2(n,m);
    vi arr;
    arr.resize(111);
    init();
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    bool is=false;
    if(arr[1]==0){
        is=true;
    }
    if(is){
        res[1][1][1][0]=1;
        res[1][1][0][1]=1;
    }
    if(is==false){
        res[1][1][arr[1]%2^1][arr[1]%2]=1;
    }
    for(int i=2;i<=n;i++){
        int term2=0;
        while(term2<=m){
            for(int term3=0;term3<=n/2;term3++){
                if((arr[i]%2==0)){
                    int leftId=term2;
                    int rightId=term3;
                    leftId--;
                    rightId--;
                    bool left=false;
                    bool right=false;
                    if(term2 && term3){
                        left=true;
                        right=true;
                    }
                    if(left && right){
                        res[i][term2][term3][0]+=res[i-1][leftId][rightId][1];
                    }
                    res[i][term2][term3][0]%=mod;
                    right=false;
                    if(term3>0){
                        right=true;
                    }
                    if(right){
                        res[i][term2][term3][0]+=res[i-1][term2][rightId][0];
                    }
                    res[i][term2][term3][0]%=mod;
                }
                if((arr[i]&1==1)||arr[i]-0==0){
                    int leftId=term2;
                    int rightId=term3;
                    leftId--;
                    rightId--;
                    bool left=false;
                    bool right=false;
                    res[i][term2][term3][1]+=res[i-1][term2][term3][1];
                    res[i][term2][term3][1]%=mod;
                    if(term2>0){
                        left=true;
                    }
                    if(left){
                        res[i][term2][term3][1]+=res[i-1][leftId][term3][0];
                    }
                    res[i][term2][term3][1]%=mod;
                }
            }
            term2++;
        }
    }
    int toE=n/2;
    int toO=n/2;
    if(n&1){
        toO++;
    }
    fl(i,1,n+1){
        bool is=false;
        if(arr[i]>0){
            is=true;
        }
        if(is){
            toE-=(arr[i]%2^1);
        }
        if(is){
            toO-=(arr[i]&1);
        }
    }
    int mAns=factorial(toE);
    mAns%=mod;
    mAns*=factorial(toO);
    mAns%=mod;
    int other=0;
    fl(q,0,2){
        other+=res[n][m][n/2][q];
        other%=mod;
    }
    other%=mod;
    mAns*=other;
    mAns%=mod;
    cout<<mAns<<endl;
    
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