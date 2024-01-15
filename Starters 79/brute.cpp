#include <bits/stdc++.h>
using namespace std;
const int MXN=2000010;
const long long MOD=998244353,INF=1000000000;
long long f[MXN],inv[MXN],finv[MXN];
void Initialize(){
	f[0]=f[1]=inv[0]=inv[1]=finv[0]=finv[1]=1;
	for (int i=2; i<MXN; i++){
		f[i]=f[i-1]*i%MOD;
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
long long nCr(int n,int r){
	if (n<r) return 0LL;
	return f[n]*finv[r]%MOD*finv[n-r]%MOD;
}
long long nHr(int n,int r){
	return nCr(n+r-1,r);
}
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	long long a[n+1];
	for (int i=1; i<=n; i++) cin>>a[i];
	long long mx[k+1];
	for (int i=1; i<=k; i++){
		mx[i]=0;
		for (int j=i; j<=n; j+=k){
			mx[i]=max(mx[i],a[j]);
		}
		for (int j=i; j<=n; j+=k){
			m-=min(INF,mx[i]-a[j]);
			if (m<0){
				cout<<"0\n";
				return;
			}
		}
	}
	long long sum[m/(n/k)+1];
	for (int i=0; i<=m/(n/k); i++){
		if (i>0) sum[i]=sum[i-1];
		else sum[i]=0;
		sum[i]+=nHr(k-n%k,i);
		sum[i]%=MOD; 
	}
	long long ans=0;
	if (n%k==0){
		int mxCnt=m/(n/k);
		cout<<sum[mxCnt]<<'\n';
		return;
	}
	for (int cntBig=0; cntBig<=m/((n+k-1)/k); cntBig++){
		int mxSmall=(m-(n+k-1)/k*cntBig)/(n/k);
		ans+=nHr(n%k,cntBig)*sum[mxSmall];
		ans%=MOD;
	}
	cout<<ans<<'\n';
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T=1;
	cin>>T;
	Initialize();
	while (T--) solve();
}