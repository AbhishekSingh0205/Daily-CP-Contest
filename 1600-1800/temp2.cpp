#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
#define nl '\n'
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))  
long double pi = 3.141592653589793238;

const int mod = 1e9 + 7;

using namespace std;

bool predicate (long double mid, vector <long double >&volume, ll f, ll n)
{
  
    // find on divideing the pie do we get >=f pieces 
  int count = 0;
  
     for (int i = 0; i < n; i++)
    {
      
        count += volume[i] / mid;
    
     } 
        return count >= f;

}


int
main ()
{
  
fastio;
  
ll t;
  cin >> t;
  while (t--)
    {
      
ll n, f;
      cin >> n >> f;
      
vector < ll > vec (n);
      
for (int i = 0; i < n; i++)
    cin >> vec[i];
    //volume of ech pie through radius  
vector <long double >volume (n);
      
for (int i = 0; i < n; i++)
    
volume[i] = vec[i] * vec[i] * pi;
      
long double sum=0;
for(int i=0;i<n;i++){
	sum+=volume[i];
}
long double lo = 1, hi = sum, ans = -1;
      
for (int i = 0; i < 100; i++)
    {
      
long double mid = (hi + lo) / 2;
      
if (predicate (mid, volume, f + 1, n))
        
        {
          
ans = mid;
          
lo = mid+1;
        
}
      else
        hi = mid-1;
    
}
      
cout << fixed << setprecision (4) << ans << nl;
    
}
  
return 0;

}