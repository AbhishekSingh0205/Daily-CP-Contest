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
int good(int mid){

}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e1(n);
    av(a,n);
    int orReq=0;
    fl(i,0,n){
        orReq|=a[i];
    }
    cerr<<"orReq\n"<<orReq<<endl;
    cerr<<"Not here"<<endl;
    int pref[n][31];memset(pref,0,sizeof pref);
    cerr<<"PREF"<<endl;
    cerr<<"SUFF"<<endl;
    int suff[n+1][31];memset(suff,0,sizeof suff);
    cerr<<"SUFFD"<<endl;
    for(int i=0;i<n;i++){
        int tmp=a[i];
        int curr=0;
        while(tmp){
            pref[i][curr]=(tmp&1);
            tmp/=2;
            curr++;
        }
        if(i){
            for(int j=0;j<31;j++){
                pref[i][j]+=pref[i-1][j];
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        int tmp=a[i];
        int curr=0;
        while(tmp){
            suff[i][curr]=(tmp&1);
            tmp/=2;
            curr++;
        }
        if(i<n-1){
            for(int j=0;j<31;j++){
                suff[i][j]+=suff[i+1][j];
            }
        }
    }
    cerr<<"Array DONE";
    int reqAr[31];memset(reqAr,0,sizeof reqAr);
    int curr=0;
    int tmp=orReq;
    while(tmp){
        if(tmp&1){
            reqAr[curr]=1;
        }
        curr++;
        tmp/=2;
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        int l=i+1,h=n-1;
        int tmp1[31];
        for(int j=0;j<31;j++){
            tmp1[j]=pref[i][j];
            if(tmp1[j]>0){
                tmp1[j]=1;
            }
        }
        bool is=true;
        for(int j=0;j<31;j++){
            if(tmp1[j]!=reqAr[j]){
                is=false;
            }
        }
        memset(tmp1,0,sizeof tmp1);
        if(i+1==n){
            is=false;
        }
        for(int j=0;j<31;j++){
            tmp1[j]=suff[i+1][j];
            if(tmp1[j]>0){
                tmp1[j]=1;
            }
            if(tmp1[j]!=reqAr[j]){
                is=false;
            }
        }
        cerr<<"Here"<<endl;
        if(is){
            pr(i,is);
            ans=max(ans,n-1-i);
            ans=max(ans,i+1);
        }
        int ind=i;
        while(l<=h){
            int mid=(l+h)/2;
            int tmp2[31];
            for(int j=0;j<31;j++){
                tmp2[j]=pref[i][j]+suff[mid][j];
                if(tmp2[j]>0){
                    tmp2[j]=1;
                }
            }
            bool is1=true;
            for(int j=0;j<31;j++){
                if(tmp2[j]!=reqAr[j]){
                    is1=false;
                }
            }
            if(is1){
                l=mid+1;
                ind=mid;
            }
            else{
                h=mid-1;
            }
        }
        ans=max(ans,ind-(i+1));
    }
    if(ans==0){
        ans=-1;
    }
    cout<<ans<<endl;





}
int32_t main()
{
    __builtin_LIVU();
    int t = 1;
    cerr<<"GO";
    cin >> t;
    fl(i, 1, t + 1) {
        solve();
    }
    return 0;
}