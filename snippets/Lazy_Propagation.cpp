struct node{
    // Node structure, for now we calculating sum, maxr and lazy (update l to r to val)
    // We can keep a separate islazy boolean variable

    int sum,maxr,lazy;
    bool islazy;
    node(){
        sum=0;
        maxr=0;
        lazy=0;
        islazy=false;
    }
};
node merge(node a,node b){
    // Change merge function
    node c;
    c.sum=a.sum+b.sum;
    c.maxr=max(a.maxr,b.maxr);
    return c;
}
// Don't need build because whole value is going to be like default value.
node segtree[N];
void push(int id,int l,int r){
    if(islazy){
        // Change the body code according to your node.
        segtree[id].maxr=v;
        segtree[id].sum=(r-l+1)*v;
        if(l!=r){
            segtree[2*id].islazy=1;
            segtree[2*id].lazy=v;
            segtree[2*id+1].islazy=1;
            segtree[2*id+1].lazy=v;
        }
        segtree[id].islazy=0;
        segtree[id].lazy=0;
    }
}
void update(int id,int l,int r,int lq,int rq,int v){
    push(id,l,r);
    if(lq>r||l>rq){
        return;
    }
    if(lq<=l && r<=rq){
        segtree[id].islazy=1;
        segtree[id].lazy=v;
        push(id,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(2*id,l,mid,lq,rq,v);
    update(2*id+1,mid+1,r,lq,rq,v);
    t[id]=merge(t[2*id],t[2*id+1]);
}
node query(int id,int l,int r,int lq,int rq){
    push(id,l,r);
    if(lq>r||l>rq){
        // Change the default value
        return node();
    }
    if(lq<=l && r<=rq){
        return segtree[id];
    }
    int mid=(l+r)/2;
    node lft=query(2*id,l,mid,lq,rq);
    node rgt=query(2*id+1,mid+1,r,lq,rq);
    return merge(lft,rgt);
}


