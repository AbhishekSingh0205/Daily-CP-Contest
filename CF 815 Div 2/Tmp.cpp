#include<bits/stdc++.h>
using namespace std;
#define inf 1e15
#define int long long int
vector<int>arr;
int dp[1000001];
int coin(int n,int t){
	if(t==0){
		return 0;
	}
	if(n<0){
		return INT_MAX;
	}
	if(dp[t]!=-1){
		return dp[t];
	}
	int ans=inf;
	if(arr[n]<=t){
		ans=1+coin(n,t-arr[n]);
	}
	ans=min(ans,coin(n-1,t));
	return dp[t]=ans;
}






signed main() {
	int n,x;cin>>n>>x;
	arr.resize(n);
	memset(dp,-1,sizeof dp);
    int i;
	for(i=0;i<n;i++){
	    int z;cin>>z;
	    arr[i]=z;
	}
	sort(arr.begin(),arr.end());
	int ab=coin(n-1,x);
	if(ab>=INT_MAX){
		cout<<-1<<endl;return 0;
	}
	cout<<ab<<endl;
	return 0;
}
