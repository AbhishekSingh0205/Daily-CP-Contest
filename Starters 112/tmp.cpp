#include<bits/stdc++.h>
using namespace std;

int vis[1001]; // ith node phle bhi visited hai ki nahi
// vis[i] = 0 -> Not visited
// vis[i] = 1 -> Visited
void dfs(int src, int par, vector<int> gr[]){
    cout<<src<<" ";
    vis[src]=1;
    for(auto v:gr[src]){
        if(v!=par && vis[v]==0){
            dfs(v,src,gr);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> gr[n+1];
    memset(vis,0,sizeof vis);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    // dfs(1,-1,gr);
    int visited[1001];
    memset(visited,0,sizeof visited);
    queue<int>q;
    q.push(1);
    visited[1]=1;
    int dis[n+1];
    dis[1]=0;
    while(q.size()!=0){
        int tp = q.front();
        q.pop();
        cout<<tp<<" ";
        for(auto v:gr[tp]){
            if(visited[v]==0){
                q.push(v);
                dis[v]=dis[tp]+1;
                visited[v]=1;
            }
        }
    }
    cout<<dis[des]<<endl;
    cout<<endl;
    
}