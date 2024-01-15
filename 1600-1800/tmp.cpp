#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
// #include "debug.h"
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
const long long INF = 1e18;
long long N = 1e5+7;

long long n,power,k;

vector<long long> par(N,-1);

long long find_dsu(long long n)
{
    if (par[n]<0) return n;
    return par[n]=find_dsu(par[n]); //path compression
}

void union_dsu(long long a, long long  b)
{
    a=find_dsu(a);
    b=find_dsu(b);
    if (a==b) return;
    // union by size
    if (abs(par[a])<abs(par[b]))    //make a the larger set
        swap(a,b);
    // a-> larger set is parent
    par[a]+=par[b];
    par[b]=a;
}

vector<vector<int>> random_graph(int n,bool dir=0,bool tree=1,int m=0){
    vector<vector<int>> adj(n+1);
    if(tree){
        for(int i=2;i<=n;i++){
            int x = random(1,i-1,int);
            adj[x].push_back(i); if(!dir) adj[i].push_back(x);
        }
        return adj;
    }
    set<pair<int,int>> st;
    for(;st.size()<m;){
        int a = random(1,n,int); int b = random(1,n,int);
        if (find_dsu(a)==find_dsu(b))   // not connected
            continue;
        if(a==b) continue;
        if(!dir && a>b) swap(a,b);
        st.insert({a,b});
        union_dsu(a,b);
    }
    for(auto p : st) {
        adj[p.first].push_back(p.second);
        if(!dir) adj[p.second].push_back(p.first);
    }
    return adj;
}


/*
	for tree : 
	       vector<vector<int>> x =random_graph(a);
        set <pair<int,int>> st;
        int n= x.size();
        for (int i=1;i<n;i++)
        {
        int sz=x[i].size();
        for (int j=0;j<sz;j++)
        {
            pair <int,int> p1={i,x[i][j]},p2={x[i][j],i};
            if (st.find(p1)==st.end() && st.find(p2)==st.end())
                st.insert(p1);
        }
        }
         for (auto &pr: st)
        cout<<pr.first<<" "<<pr.second<<endl;
*/
int main(){
	int n=5;// Number of nodes.
	vector<vector<int>>gr=random_graph(n);// adjacency list.
	for(auto v:gr){
		for(auto vv:v){
			cout<<vv<<" ";
		}
		cout<<endl;
	}
}