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
#define mod 2
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
// Overloading for mod

struct mint
{
    int val;
    mint(int _val = 0)
    {
        val = _val % mod;
    }
    mint operator+(mint oth)
    {
        return val + oth.val;
    }
    mint operator*(mint oth)
    {
        return 1LL * val * oth.val;
    }
    mint operator-(mint oth)
    {
        return val - oth.val + mod;
    }
    void operator+=(mint oth)
    {
        val = (mint(val) + oth).val;
    }
    void operator-=(mint oth)
    {
        val = (mint(val) - oth).val;
    }
    void operator*=(mint oth)
    {
        val = (mint(val) * oth).val;
    }
};
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    e1(n);es(s);
    map<char,int>m;
    fl(i,0,n){
        m[s[i]]++;
    }
    map<char,vi>m2;
    fl(i,0,n){
        m2[s[i]].pb(i);
    }
    string ans;
    ans.resize(n,'.');
    int res=inf;
        int num=0;
        vector<int>aa;
        for(auto v:m){
            aa.pb(v.ss);
        }
        sort(all(aa));reverse(all(aa));
        for(int cnt=1;cnt<=n;cnt++){
            if(n%cnt==0 && cnt*26>=n){
                int len=0;
                int tmp=0;
                for(int i=0;i<aa.size();i++){
                    if(len==n){
                        B;
                    }
                    else{
                        if(aa[i]>=cnt){
                            // tmp+=abs(aa[i]-cnt);
                            len+=cnt;
                        }
                        else{
                            tmp+=(cnt-aa[i]);
                            len+=cnt;
                        }
                    }
                }
                tmp+=(n-len);
                // pr(tmp,cnt);
                if(tmp<res){
                    res=tmp;
                    num=cnt;
                }
            }
        }
        // pr(num);
        vector<pii>req;
        for(auto v:m2){
            if(v.ss.size()>=num){
                int tmp=num;
                vi arr=v.ss;
                while(tmp){
                    ans[arr.back()]=v.ff;
                    tmp--;
                    arr.pop_back();
                }
            }
            else{
                int pos=v.ff-'a';
                req.pb({-1*v.ss.size(),pos});
            }
        }
        int charN=0;
        for(int i=0;i<n;i++){
            if(ans[i]=='.')charN++;
        }
        charN/=num;
        if(charN==0){
            int diff=0;
            for(int i=0;i<n;i++){
                if(s[i]!=ans[i]){
                    diff++;
                }
            }
            cout<<diff<<endl;
            cout<<ans<<endl;R;
        }
        sort(all(req));
        if(req.size()){
            int sz=req.size();
            for(int i=0;i<min(sz,charN);i++){
                int tmp=m[char('a'+req[i].ss)];
                while(tmp){
                    ans[m2[char('a'+req[i].ss)].back()]=char('a'+req[i].ss);
                    m2[char('a'+req[i].ss)].pop_back();
                    tmp--;
                }
            }
            vector<int>free;
            for(int i=0;i<n;i++){
                if(ans[i]=='.')free.pb(i);
            }
            for(int i=0;i<min(sz,charN);i++){
                int tmp=num-m[char('a'+req[i].ss)];
                while(tmp){
                    ans[free.back()]=char('a'+req[i].ss);
                    free.pop_back();
                    tmp--;
                }
            }
        }
        int diff=0;
        vector<int>free;
        for(int i=0;i<n;i++){
            if(ans[i]=='.')free.pb(i);
        }
        if(free.size()){
            vector<int>kk;
            for(int i=0;i<26;i++){
                if(m.find(char(i+'a'))==m.end()){
                    kk.pb(i);
                }
            }
            while(free.size()){
                for(int i=0;i<kk.size();i++){
                    int tmp=num;
                    while(tmp && free.size()){
                        ans[free.back()]=char(kk[i]+'a');
                        free.pop_back();
                        tmp--;
                    }
                    if(free.size()==0){
                        B;
                    }
                }
            }
        }
        
        diff=0;
        for(int i=0;i<n;i++){
            if(s[i]!=ans[i]){
                diff++;
            }
        }
        cout<<diff<<endl;
        cout<<ans<<endl;R;

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