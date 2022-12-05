#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define e endl
#define f(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pb push_back
#define i1(a) \
    ll a;    \
    cin >> a;
#define i2(a, b) \
    ll a, b;    \
    cin >> a >> b;
#define i3(a, b, c) \
    ll a, b, c;    \
    cin >> a >> b >> c;  
#define is(str) \
    string str; \
    cin>>str;
#define vi(arr, n)    \
    vector<ll> arr(n); \
    f(i, 0, n) cin >> arr[i];
#define printv(arr,n) \
    f(i,0,n) cout<<arr[i]<<' ';
#define mod 1000000007
#define ff first
#define ss second
#define mll map<ll,ll>
#define R return
#define light ios_base::sync_with_stdio(false); \
        cin.tie(NULL); 
#define B break
#define C continue
#define YC cout << "YES" 
#define NC cout << "NO" 


ll add(ll a, ll b){
    return (a%mod+b%mod)%mod;
}

ll sub(ll a, ll b){
    return (a%mod-b%mod+mod)%mod;
}

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}
map<ll,ll> fun(ll n){
    map<ll,ll> mape;
    for(ll i=2; i<=sqrt(n); ++i){
        while(n%i==0){
            mape[i]++;
            n/=i;
        }
    }
    if(n>1) mape[n]++;
    return mape;
}

void solve()
{
    i1(k);
    ll ans = k;
    ll lo = 1, hi = k;
    map<ll,ll> mape = fun(k);
    
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        map<ll,ll> mape2;
        cout<<"mid: "<<mid<<e; 
        ll org = mid;
        for(ll j=2; j<=(ll)sqrt(mid); j++){
            bool yes = false;
            ll var = 0;
            cout<<"j: "<<j<<e;
            while(mid%j==0){
                var++;
                if(var>2){
                    cout<<"exit: "<<mid<<" "<<j<<e; break; 
                }
                yes = true;
                mid = mid/j; 
                break; 
            }
            if(yes){
                ll cnt = org/j;
                ll val = j, power = 1;
                while(val<=org){
                    val*=j;
                    power++;
                }
                power-=2;
                power = max(0kll,power);
                cnt+=(power*(power+1))/2;
                mape2[j] = cnt;
                cout<<"j: "<<j<<" "<<cnt<<e;
            }
        }
        bool ok = true;
        for(auto &x: mape){
            if(mape2.find(x.ff)==mape2.end() || mape2[x.ff]<x.ss){
                ok = false; break; 
            }
        }
        if(ok){
            cout<<"mid: "<<mid<<e; 
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1; 
    }
    cout<<ans<<e; 
}
int32_t main()
{
    light

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}