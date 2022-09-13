#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	// Your code here
    int t = 1;
    cin >> t;
    while(t--) {
        int n;cin>>n;
        string s;cin>>s;
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') cnt1++;
            else cnt0++;
        }
        if(cnt1%4==0){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}
