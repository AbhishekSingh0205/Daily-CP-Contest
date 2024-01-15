#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int,int>
#define mp make_pair
class priortize{
        public:bool operator()(pii p1,pii p2){
            return p1.ss>p2.ss;
        }
    };
int solve(int n,vector<vector<int>>edges,int source,int destination){
    vector<pair<int,int>>gr[n+1];
    int N=n+1;
    int inf = INT_MAX;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        gr[u].push_back({v,wt});
        gr[v].push_back({u,wt});
    }
    
    // Assuming n,m and graph gr is global.
    int dis[N];
    int vis[N];
    for(int i=0;i<n;i++){
        dis[i]=inf;
        vis[i]=0;
    }
    dis[source]=0;    
    priority_queue<pii,vector<pii>,priortize>pq;
    pq.push(mp(source,0));
    while(!pq.empty()){
        pii fr=pq.top();
        pq.pop();
        if(vis[fr.ff]){
            continue;
        }
        vis[fr.ff]=1;
        for(auto v:gr[fr.ff]){
            int neig=v.ff;
            int wt=v.ss;
            int newWt = max(fr.ss,wt);
            if(dis[neig]>newWt){
                dis[neig]=newWt;
                pq.push(mp(neig,dis[neig]));
            }
        }
    }
    int ans=INT_MAX;
    for(auto v:gr[destination]){
        ans=min(ans,dis[v.ff]);
    }
    return ans;
}
int main(){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> edges(m,vector<int>(3));
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++){
            cin>>edges[i][j];
        }
    }
    int src,dest;
    cin>>src>>dest;
    cout<<solve(n,edges,src,dest);
}