class priortize{
    public:bool operator()(pii p1,pii p2){
        return p1.ss>p2.ss;
    }
};
// Assuming n,m and graph gr is global.
int dis[N];
int vis[N];
// For storing the path
int parU[N];//parent of U is ->parU
void dijikstra(int src){
    // Reseting each node
    for(int i=0;i<=n;i++){
        dis[i]=inf;
        vis[i]=0;
        parU[i]=-1;
    }
    dis[src]=0;
    // pii->{node,dis_from_src}
    priority_queue<pii,vector<pii>,priortize>pq;
    pq.push(mp(src,0));
    while(!pq.empty()){
        pii fr=pq.top();
        pq.pop();
        // If once that node is relaxed then we will not take that not again.
        if(vis[fs.ff]){
            C;
        }
        // Else we will process
        vis[fs.ff]=1;
        for(auto v:gr[fr.ff]){
            int neig=v.ff;
            int wt=v.ss;
            if(dis[neig]>dis[fs.ff]+wt){
                dis[neig]=dis[fs.ff]+wt;
                pq.push(mp(neig,dis[neig]));
                parU[neig]=fs.ff;
            }
        }
    }
    // parU will tell us the path.
}