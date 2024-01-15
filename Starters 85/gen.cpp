#include <bits/stdc++.h>

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define random(l,r,T)    uniform_int_distribution<T>(l,r)(rng)
signed main(signed argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(atoi(argv[1]));

    // generate test cases with same format as given in problem
    int t=10;
    cout<<t<<endl;
    while(t--){
        int n,m;
        n=5;cout<<n<<endl;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            a[i]=random(1,25,int);
            cout<<a[i]<<" ";
        }
        cout<<endl;
        int q=random(1,n,int);
        cout<<q<<endl;
        while(q--){
            int x=random(1,25,int);
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}