#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=1e9+7;

#ifdef ANI
#include "D:/DUSTBIN/local_inc.h"
#else
#define dbg(...) 0
#endif

ll fastexp(ll base,ll exp) {
	ll res=1;
	base%=mod;
	while(exp) {
		if(exp&1) res=(res*base)%mod;
		base=(base*base)%mod;
		exp>>=1;
	}
	return res;
}
 
ll modinv(ll num) {
	return fastexp(num, mod-2);
}
 
vector<ll> factorial,inv_factorial;
void compute_factorial(ll n=1e6) {
	factorial=inv_factorial=vector<ll>(n+1,1);
	for(ll i=2;i<n+1;i++) {
		factorial[i]=factorial[i-1]*i%mod;
	}
	inv_factorial[n]=modinv(factorial[n]);
	for(ll i=n-1;i>0;i--) {
		inv_factorial[i]=inv_factorial[i+1]*(i+1)%mod;
	}
}
 
ll ncr(ll n,ll r) {
	if(r>n or r<0 or n<0) return 0;
	return factorial[n]*((inv_factorial[r]*inv_factorial[n-r])%mod)%mod;
}

class Testcase{
public:
	ll n,ans=-1;
	vector<array<ll,2>> edges;
	vector<vector<ll>> adj;
	Testcase(vector<array<ll,2>> edges) {
		// 0 indexed
		this->n=edges.size()+1;
		this->edges=edges;
		this->adj=vector<vector<ll>>(n);
		for(ll i=0;i<n-1;i++) {
			adj[edges[i][0]].push_back(edges[i][1]);
			adj[edges[i][1]].push_back(edges[i][0]);
		}
	}
	Testcase(vector<vector<ll>> adj) {
		this->adj=adj;
		this->n=adj.size();
		for(ll i=0;i<n;i++) {
			for(ll j:adj[i]) {
				if(i<j) {
					(this->edges).push_back({i,j});
				}
			}
		}
	}

	void write(ofstream &inp, ofstream &out) {
		inp<<n<<"\n";
		for(ll i=0;i<n-1;i++) {
			inp<<edges[i][0]+1<<" "<<edges[i][1]+1<<"\n";
		}
		assert(this->ans != -1);
		out<<(this->ans)<<"\n";
	}
};

ll solution(Testcase &tc) {
	auto e=tc.adj;
	ll n=tc.n;
	vector<ll> dp(n,0);

	function<ll(ll,ll)> dfs=[&](ll cur,ll par)->ll{
		ll p=1,c=1;
		for(ll node:e[cur]) {
			if(node==par) continue;
			c+=dfs(node,cur);
			p=(p*dp[node])%mod;
		}
		dp[cur]=(ncr(c,c/2)*p)%mod;
		return c&1;
	};

	return tc.ans=(1+dfs(0,-1))*dp[0]%mod;
}

void main_() {
	compute_factorial();

    ll t; cin>>t;
    assert(t<=1e4);
    ll nsum=0;
    while(t--) {
    	ll n; cin>>n; nsum+=n;
    	vector<array<ll,2>> tree;
    	for(ll i=0;i<n-1;i++) {
    		ll u,v; cin>>u>>v;
    		tree.push_back({u-1,v-1});
    	}
    	// dbg(tree);
    	auto tc_=Testcase(tree);
    	solution(tc_);
    	cout<<tc_.ans<<"\n";
    }
    assert(nsum<=3e5);
}

int main() {
main_();
}