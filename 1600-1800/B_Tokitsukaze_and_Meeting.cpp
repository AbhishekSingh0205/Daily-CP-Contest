//Problem Link : https://codeforces.com/contest/1677/problem/B
//Author -> Vaibhavi Shekhawat
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
void solve()
{
    /*It's WA on 2, oh cleared, This shit is onna get me TLE. Better luck next time buddy.*/
    /*
        We can find the answers for Rows and Column independently.
        Row Calculations ------------------
        dpr[i]-> Number of rows When ith child comes.
        dpr[i]=dpr[i-m] + (any of last m elements==1)
        For calculation of (any of last m elements==1) we can use multiset st.
        if(*st.rbegin()==1) -> It means there is atleast 1 element with value 1 in last set of m elements.

        Column Calculations ----------------
        We can see that answer will be either same or increase by 1. It will never decrease.
        For the answers of columns, we can observe that since there are only n⋅m
        students in total, no students will leave, and every time a new student entering the meeting hall, all columns will move one step to the right circularly, so the answer will not decrease. If the i-th student is a serious student, for all the previous students with j where 0<j<i
        , and j%m=i%m are naughty students, the answer in the column will increase by 1.
    */
    int n,m;cin>>n>>m;
    es(s);
    int dpr[n*m];
    multiset<int>st;   
    for(int i=0;i<m;i++){
        st.insert(s[i]-'0');
        if(*st.rbegin()==1){
            dpr[i]=1;
        }
        else{
            dpr[i]=0;
        }
    }
    int id=0;
    for(int i=m;i<n*m;i++){
        st.erase(st.find(s[id]-'0'));
        st.insert(s[i]-'0');
        dpr[i]=dpr[i-m];
        if(st.size() && *st.rbegin()==1){
            dpr[i]++;
        }
        id++;
    }
    // return;
    int col[n*m];
    set<int> a[m];
    int prevAns=0;
    for(int i=0;i<n*m;i++){
        if((a[i%m].size()) && *(a[i%m].rbegin())==1){
            col[i]=prevAns;
        }
        else if(s[i]-'0'==1){
            prevAns++;
            a[i%m].insert(1);
            col[i]=prevAns;
        }
        else{
            col[i]=prevAns;
        }
    }
    for(int i=0;i<n*m;i++){
        cout<<dpr[i]+col[i]<<" ";
    }
    cout<<endl;
    


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