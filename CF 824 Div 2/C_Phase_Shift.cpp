#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int n,m,a[101],dp[101][101][101][2];
int frac(int x) {
   int p=1;
   for(int i=1;i<=x;++i)
      p=(p*i)%MOD;
   return p;
}
void solve() {
    memset(dp,0,sizeof(dp));
    cin >> n >> m;
    for(int i=1; i<=n; ++i)
        cin >> a[i];
    if(a[1]==0) {
        dp[1][1][1][0]=1;
        dp[1][1][0][1]=1;
    } else
        dp[1][1][a[1]%2^1][a[1]%2]=1;
    for(int i=2; i<=n; ++i) { //index
        for(int j=0; j<=m; ++j) { //ÃÀÀö
            for(int k=0; k<=n/2; ++k) { //ÊÓÃµÄÅÊýöÊý
                if(a[i]%2==0) {
                    if(k!=0&&j!=0) dp[i][j][k][0]+=dp[i-1][j-1][k-1][1];
                    if(k!=0)       dp[i][j][k][0]+=dp[i-1][j][k-1][0];
                    dp[i][j][k][0]%=MOD;
                }
                if(a[i]%2==1||a[i]==0) {
                    dp[i][j][k][1]+=dp[i-1][j][k][1];
                    if(j!=0)       dp[i][j][k][1]+=dp[i-1][j-1][k][0];
                    dp[i][j][k][1]%=MOD;
                }
            }
        }
    }
    int even=n/2,odd=(n+1)/2;
    for(int i=1;i<=n;++i)
       if(a[i]!=0) {
          even-=a[i]%2^1;
          odd-=a[i]%2;
       }
    cout << frac(odd)*frac(even)%MOD*(dp[n][m][n/2][0]+dp[n][m][n/2][1])%MOD << endl;
}
signed main() {
    int T;
    cin >> T;
    while(T--) solve();
}