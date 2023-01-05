struct NODE{
    int pref[26],lazy[26];
    bool isLazy;
    NODE{
        memset(pref,0,sizeof pref);
        isLazy=0;
        memset(lazy,0,sizeof lazy);
    }
};

NODE segTree[4*M][N];
void pushLazy(int node,int rowN,int start,int end){
    if(isLazy){
        for(int i=0;i<26;i++){
            segTree[node][rowN].pref[i]+=segTree[node][rowN].lazy[i];
        }
        if(start!=end){
            for(int i=0;i<26;i++){
                segTree[2*node][rowN].lazy[i]+=segTree[node][rowN].lazy[i];
            }
            for(int i=0;i<26;i++){
                segTree[2*node+1][rowN].lazy[i]+=segTree[node][rowN].lazy[i];
            }
        }
        isLazy=0;
        for(int i=0;i<26;i++){
            segTree[node][rowN].lazy[i]=0;
        }
    }
}
NODE combine(NODE a,NODE b){
    // Can be modified according to the question.
    NODE c;
    
    return c;
}
void build(int node,int start,int end){
    if(start==end){
        // Can be changed according to the question
        segTree[node].ans=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind,int val){
    if(start==end){
        // Can be changed according to the question
        segTree[node].ans=val;
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind,val);
    }
    else{
        update1(2*node,start,mid,ind,val);
    }
    segTree[node]=combine(segTree[2*node],segTree[2*node+1]);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return segTree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r);
    NODE rq=query(2*node+1,mid+1,end,l,r);
    return combine(lq,rq);
}