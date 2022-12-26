vi gr[N];
int tme[N];
int tmp=1;
int dis[N];
int pare[N][22];
bool good(int a,int b){
    if(tme[a]>=tme[b]){
        return false;
    }
    return true;
}
void dfs(int src,int par,int cnt){
    tme[src]=tmp;
    tmp++;
    dis[src]=cnt;
    pare[src][0]=par;
    for(int i=1;i<22;i++){
        if(pare[src][i-1]>=0) pare[src][i]=pare[pare[src][i-1]][i-1];
    }
    for(auto v:gr[src]){
        if(v!=par){
            dfs(v,src,cnt+1);
        }
    }
}
int lca(int a,int b){
    if(dis[a]<dis[b]){
        swap(a,b);
    }
    for(int i=21;i>=0;i--){
        if((dis[a]-dis[b])&(1<<i)){
            a=pare[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=21;i>=0;i--){
        if(pare[a][i]!=pare[b][i]){
            a=pare[a][i];
            b=pare[b][i];
        }
    }
    return pare[a][0];
}
int findK(int src,int k){
    for(int i=21;i>=0;i--){
        if(k&(1<<i)){
            src=pare[src][i];
        }
    }
    return src;
}
