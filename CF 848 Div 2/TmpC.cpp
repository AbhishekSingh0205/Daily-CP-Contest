#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
 void func(ll i,ll res, vector<char>&temp, string str1, string str2, ll k, ll &ans){
           if(i==temp.size()){
            vector<bool>mp(26,0);
            int cnt=0;
              for(ll j = 0; j<temp.size(); j++){
                // cout<<res<<" "<<(1<<j)<<" "<<(res&(1<<j))<<endl;
                 if((res&(1<<j))>0){
                  mp[temp[j]-'a'] = 1;
                  cnt++;
                 }

              }
              if(cnt<=k){
                  ll result = 0, ct = 0;
                  for(ll j = 0; j<str1.size(); j++){
                   
                       if(str1[j]==str2[j] || mp[str1[j]-'a']==1){
                        ct++;
                      }
                      else{
                        result = result+(ct*(ct+1))/2;
                        ct = 0;
                      }
                    
                  }
                  result = result+(ct*(ct+1))/2;
                  ans = max(result,ans);
              }
               return;
           }
           func(i+1,res+(1<<i),temp,str1,str2,k,ans);
           func(i+1,res,temp,str1,str2,k,ans);
 }
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--){
    ll n, k;
    cin>>n>>k;
    string str1;
    cin>>str1;
    string str2;
    cin>>str2;
    set<char>st;
    for(ll i = 0; i<n; i++){
      st.insert(str1[i]);
    }
    vector<char>temp;
    for(auto iter : st){
      temp.push_back(iter);
    }
   
    ll ans = 0;
    func(0,0,temp,str1, str2,k,ans);
    cout<<ans<<"\n";
    
  }
  return 0;
}