#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        if (n >= 2 && n <= 10)
        {
            cout << "NO" << endl;
        }
        else
        {
            long long int a = n, b = n, c = n;

            for (long long int i = 2; i * i <= n; i++)
            {
                if ((n % i) == 0)
                {
                    a = i;
                    break;
                }
            }
            n = n / a;
            // cout<<"n "<<n<<endl;
            bool is=false;
            // int b=1,c=1;
            for(int i=2;i*i<=n;i++){
                if(n%i==0){
                    if(i!=a && (n/i)!=a && i!=(n/i)){
                        b=i;c=n/i;
                        is=true;
                        break;
                    }
                }
            }
            if(is){
                cout<<"YES"<<endl;
                cout<<a<<" "<<b<<" "<<c<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}