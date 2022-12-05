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
vi preComp;
string s;
vi nextPos;
int n;
bool comp(int mid,int lst){
    int cnt1=preComp[lst]-preComp[mid];
    if(s[mid]=='1'){
        cnt1++;
    }
    int crctPos=lst-cnt1+1;
    int np1=nextPos[mid];
    if(np1>lst){
        return true;
    }
    int cntt=preComp[crctPos];
    if(s[crctPos]=='1'){
        cntt--;
    }
    cntt-=preComp[np1];
    if(cntt>0){
        return false;
    }
    return true;

}
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
        Logic : In a given string, if it's there is atleas one position in between to it's current position and sorted correct position(not inclusive), then it is not good string.

        Now finding the substrings, we can iterate from the last, and maintain the frequecny of till that index.
        
        We will iterate from last, and count how substrings end at current postion(i), and are good substrings. good substrings can be checked by binary search.


        
        Check comp function of binary search.

        We also have to maintian nearest next postion of 1, if current position is 1, then it's nextPos[i] will i itself.
        Why this so? Because, suppose in binary search if any number is number 0(s[mid]=='0'), then we will check for nextPos[mid], check for that one, if that found good, then for this mid positon comp will
        return true.


    */    
    s.clear();
    cin>>n;
    s.resize(0);
    cin>>s;
    // Calculating the frequency of 1
    preComp.resize(0);
    preComp.clear();
    preComp.resize(n,0);
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            preComp[i]++;
        }
        if(i){
            preComp[i]+=preComp[i-1];
        }
    }

    // Calculating nextpos
    nextPos.clear();
    nextPos.resize(0);
    nextPos.resize(n,n);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1'){
            nextPos[i]=i;
        }
        else if(i+1<n){
            nextPos[i]=nextPos[i+1];
        }
    }

    // Calculating the number of substrings, ending at i
    int sum=0;
    for(int i=n-1;i>=0;i--){
        int lo=0,hi=i;
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(comp(mid,i)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        sum+=(i-ans+1);
    }
    cout<<sum<<endl;



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