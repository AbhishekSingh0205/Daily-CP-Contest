struct NODE{
    // Can be modified according to the question.
    int ans;
    // Setting the value for default value.
    NODE():ans(0){}
};
NODE tree[4*N];
NODE combine(NODE a,NODE b){
    // Can be modified according to the question.
    NODE c;
    c.ans=a.ans+b.ans;
    return c;
}
void build(int node,int start,int end){
    if(start==end){
        // Can be changed according to the question
        tree[node].ans=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=combine(tree[2*node],tree[2*node+1]);
}
// Single Value update -> update1
void update1(int node,int start,int end,int ind,int val){
    if(start==end){
        // Can be changed according to the question
        tree[node].ans=val;
        return;
    }
    int mid=(start+end)/2;
    if(ind>mid){
        update1(2*node+1,mid+1,end,ind,val);
    }
    else{
        update1(2*node,start,mid,ind,val);
    }
    tree[node]=combine(tree[2*node],tree[2*node+1]);
}
// query without lazy propagation.
NODE query(int node,int start,int end,int l,int r){
    // First case out of bound, means (l,r) range is not in (start,end)
    if(start>r||end<l){
        return NODE();
    }
    // If (l,r) is inside (start,end)
    if(start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    NODE lq=query(2*node,start,mid,l,r);
    NODE rq=query(2*node+1,mid+1,end,l,r);
    return combine(lq,rq);
}
