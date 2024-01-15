/*************SOLUTION BY ADARSH SHARAD PANDEY*************/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define double long double
#define hashmap unordered_map<int,int> hash
#define hashset unordered_set<int> hash
#define createFrequencyTable for(int i=0;i<n;i++) hash[arr[i]]++;
#define setArray for(int i=0;i<n;i++) hash.insert(arr[i])
#define presentInSet (hash.find(a)!=hash.end())
#define pb push_back
#define min_heap priority_queue <int, vector<int>, greater<int>>
#define max_heap priority_queue<int>
#define arrayInput for(int i=0;i<n;i++) cin>>arr[i]
#define nahi cout<<"NO"<<endl
#define haan cout<<"YES"<<endl
#define sortArray sort(arr.begin(),arr.end())

int tempo(int n) 
{
    int l = 0, r = 3e6;
    while (r - l > 1)
    {
        int mid = (r+l) / 2;
        if ((mid * mid * mid) > n)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int32_t main()
{
    int t; cin>>t;
    while(t--)
    {
        int x; cin>>x;
        int n= x;
        while (n - tempo(n*n) < x)
        {
            int y = n*n;
            int z = tempo(y);
            n = x + z;
        }
        cout << n*n << endl;
        1002002333332443556
    }
    return 0;
}

/*************SOLUTION BY ADARSH SHARAD PANDEY*************/

