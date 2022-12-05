#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>a; //array of points on ith day.
vector<vector<int>>dp; //dp[n][3]
int rec(int i,int j,int n){
    if(i==n){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=0;
    if(j==0){
        ans=max(a[i][1]+rec(i+1,1,n),a[i][2]+rec(i+1,2,n));    
    }
    else if(j==1){
        ans=max(a[i][0]+rec(i+1,0,n),a[i][2]+rec(i+1,2,n));
    }
    else{
        ans=max(a[i][0]+rec(i+1,0,n),a[i][1]+rec(i+1,1,n));
    }
    return dp[i][j]=ans;
    
}
int main(){
    int n;cin>>n;
    a.resize(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int x;cin>>x;
            a[i][j]=x;
        }
    }
    //Putting all the values of dp to be -1.
    dp.resize(n,vector<int>(3,-1));
    dp[0][0]=a[0][0]+rec(1,0,n);
    dp[0][1]=a[0][1]+rec(1,1,n);
    dp[0][2]=a[0][2]+rec(1,2,n);
    cout<<max({dp[0][0],dp[0][1],dp[0][2]})<<endl;


}