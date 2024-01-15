#include <bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(atoi(argv[1]));
    int t=10;
    cout<<t<<endl;
    while(t--){
        int n=random(1,20,int),m=random(1,20,int),k=random(1,n,int);
        cout<<n<<" "<<m<<" "<<k<<endl;
        for(int i=0;i<n;i++){
            cout<<random(1,30,int)<<" ";
        }
        cout<<endl;
    }
    // generate test cases with same format as given in problem

    return 0;
}