#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// Instead of less<int>, we can use greater<int>, less_equal<int> for descending, and having multiple occurence respectivly
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

void solve()
{
	int n;cin>>n;
	if(n==3){
		cout<<-1<<endl;
	}
	else{
		int a[n];
		for(int i=0;i<n-1;i++){
			a[i]=i+2;
		}
		a[n-1]=1;
		for(int i=0;i<n-3;i++){
			if((a[i]^a[i+1])==a[i+2]){
				cout<<"Yes"<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
			}
		}
		
		if((a[n-2]^a[n-3])==a[n-1]){
			swap(a[0],a[n-1]);
		}
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		// cout<<endl;
		
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}