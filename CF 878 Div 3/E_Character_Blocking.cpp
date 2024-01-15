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
int mod1=1000000007;
int mod2=1000000021;
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
int sqrtll(int n) { int lo=0,hi=3037000499; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi<=n) { return hi; } return lo; }
int cbrtll(int n) { int lo=0,hi=2097151; while (hi-lo>1) { int m=(hi+lo)/2; if (m*m*m<=n) { lo=m; } else { hi=m-1; }} if (hi*hi*hi<=n) { return hi; } return lo; }
void modVal(int &a,int mod1)
{
        a%=mod1;a+=mod1;a%=mod1;
}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*USE DOUBLE HASHING RATHER THAN SINGLE HASHING !!!!*/
    es(s1);es(s2);
    e2(t,q);
    int n=s1.size();
    int time=1;
    map<int,int> cntD;
    int res=0;
    fl(i,0,n){
        if(s1[i]!=s2[i]) res++;
    }
    while(q--){
        e1(tp);
        if(cntD[time]){
            res++;
        }
        if(tp==1){
            e1(ind);
            ind=ind-1;
            bool isT=false;
            if(s1[ind]!=s2[ind]){
                isT=true;
            }
            if(isT){
                res--;
            }
            cntD[time+t]++;
            if(isT==false){
                cntD[time+t]--;
            }
        }
        else if(tp==2){
            e2(sn1,pn1);
            e2(sn2,pn2);
            pn1=pn1-1;
            pn2=pn2-1;
            if(s1[pn1]==s2[pn1]){
                res++;
            }
            char tmpA[2];
            if(sn1==1 && sn2==1){
                tmpA[0]=s1[pn1];
                tmpA[1]=s1[pn2];
            }
            else if(sn1==1 && sn2==2){
                tmpA[0]=s1[pn1];
                tmpA[1]=s2[pn2];
            }
            else if(sn1==2 && sn2==2){
                tmpA[0]=s2[pn1];
                tmpA[1]=s2[pn2];
            }   
            else if(sn1==2 && sn2==1){
                tmpA[0]=s2[pn1];
                tmpA[1]=s1[pn2];
            }
            if(s1[pn2]==s2[pn2]){
                res++;
            }
            if(sn1==1 && sn2==1){
                s1[pn1]=tmpA[1];
                s1[pn2]=tmpA[0];
            }
            else if(sn1==1 && sn2==2){
                s1[pn1]=tmpA[1];
                s2[pn2]=tmpA[0];
            }
            else if(sn1==2 && sn2==1){
                s2[pn1]=tmpA[1];
                s1[pn2]=tmpA[0];
            }
            else if(sn1==2 && sn2==2){
                s2[pn1]=tmpA[1];
                 s2[pn2]=tmpA[0];
            }
            if(s1[pn1]==s2[pn1]){
                res=res-1;
            }
            if(s1[pn2]==s2[pn2])
            {
                res=res-1;
            }
        }
        else if(tp==3){
            if(res==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        time++;
    }
    

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