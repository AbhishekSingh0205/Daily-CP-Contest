#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mx = 1e18;
void add(vector<ll>&tree, int l,int r, ll ele, int pos, int treeNode){
    if(l==r){
        tree[treeNode] = ele;
        return;
    }
    int mid = (l+r)/2;
    int left = 2*treeNode;
    int right = left+1;
    if(pos <= mid){
        add(tree,l,mid,ele,pos,left);
    }else{
        add(tree,mid+1,r,ele,pos,right);
    }
    tree[treeNode] = min(tree[left], tree[right]);
}

int query(vector<ll>&tree, int l,int r,int i,int j,ll&x, int treeNode){
    if(l>j || tree[treeNode]>x) return j+1;
    if(l == r){
        return l;
    }
    int mid = (l+r)/2;
    int left = 2*treeNode;
    int right = left+1;
    if(tree[left] <= x){
        return query(tree,l,mid,i,j,x,left);
    }
    return query(tree,mid+1,r,i,j,x,right);
}
int solve(vector<ll>&a, vector<ll>&b, vector<ll>&c){
    int ans = 0;
    int n = a.size();
    vector<ll>tree(4*n, mx);
    vector<pair<ll,int>>sum(n+1);
    vector<ll>sum2(n+1,0);
    for(int i=0;i<n;i++){
        ll diff = a[i]-b[i];
        sum[i+1] = {diff,i+1};
        sum2[i+1] = a[i]-c[i];
        if(i>0){
            sum[i+1].first += sum[i].first;
            sum2[i+1] += sum2[i];
        }
    }
    sum[0] = {0LL,0};
    sort(sum.begin(),sum.end());
    for(int i=0;i<=n;i++){
        int l=0,id=sum[i].second,r=id;
        int res = query(tree,0,n,0,id,sum2[id],1);
        add(tree,0,n,sum2[id],id,1);
        if(res > id) continue;
        ans = max(ans, id-res);
    }
    return ans;
}
int main() {
	// your code goes here
	int tt; cin>>tt;
	while(tt--){
	    int n; cin>>n;
	    vector<ll>a(n),b(n),c(n);
	    for(int j=0;j<n;j++) cin>>a[j];
	    for(int j=0;j<n;j++) cin>>b[j];
	    for(int j=0;j<n;j++) cin>>c[j];
	    cout<<solve(a,b,c)<<" ";
	    cout<<solve(b,a,c)<<" ";
	    cout<<solve(c,a,b)<<"\n";
	}
	return 0;
}
