#include<bits/stdc++.h>
using namespace std;
bool good(int mid,vector<int> &x,int k){
    int prev=x[0];
    int cnt=1;
    int n=x.size();
    for(int i=1;i<n;i++){
        if(x[i]-prev>=mid){
            prev=x[i];
            cnt++;
        }
    }
    if(cnt>=k){
        return true;
    }
    return false;
}
int maximizeMinimumDistance(vector<int> x,int k){
    sort(x.begin(),x.end());
    long long int lo=0, hi=INT_MAX;
    long long ans = lo;
    while(lo<=hi){
        long long int mid=(lo+hi)/2;
        if(good(mid,x,k)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int k;cin>>k;
    cout<<maximizeMinimumDistance(a,k);
}

// A B C D E F G 
// 1 2 3 4 5 6 7
// A B D E C F G
// 1 2 4 5 3 6 7

// D E B F G C A
// 4 5 2 5 7 3 1