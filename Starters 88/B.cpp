#include<bits/stdc++.h>
using namespace std;

typedef bool boo;
typedef int li;
typedef long il;
typedef long long int ll;


const ll MOD = 1e9+7;
const int N = 1e5+1;
///___ L E T ' S  B E G I N ____

ll fac[N],inv[N];

long long modpow(long long x, long long y, long long p) {
 long long ret = 1;
 while (y > 0) {
 if (y % 2 == 1) {
 ret = (ret * x) % p;
 }
 y /= 2;
 x = (x * x) % p;



 }
 return ret;
} 


void solve()
{
 fac[0] = inv[0] = 1;
 for (int i = 1; i < N; i++) {
 fac[i] = (i * fac[i - 1]) % MOD;
 inv[i] = modpow(fac[i], MOD - 2, MOD);

 }
}

int main() {
 // your code goes here
 solve();
 long long n;
 cin>>n;
 map<long long,long long> m;
 for(long long j=0;j<n;j++)
 {
 long long x,y;
 cin>>x>>y;
 ++m[x];
 }
 long long p=1;

 for(map<long long,long long>::iterator itr=m.begin();itr!=m.end();itr++)
 {
 p=(p*(fac[itr->second]%MOD))%MOD;
 }
 cerr<<p<<endl;
 cout<<(p*inv[n])%MOD<<"\n";
 cerr<<n<<" "<<inv[n]<<endl;
 return 0;
}