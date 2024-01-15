#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000000
#define MOD 1000000007

void solve(int tc)
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    unordered_map<int,vector<pair<int,int> > > m;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<j;i++)
        {
            m[a[i]+a[j]].push_back({i,j});
        }
    }
    int ans = n;
    for(auto z:m)
    {
        auto v = z.second;
        int mx = 0;
        map<int,int> dp;
        int j = 0;
        for(auto p:v)
        {
            int op1 = 0, op2 = 0;
            // if (j!=0) dp[p.second] = max(dp[v[j-1].second],dp[p.second]);
            if (j!=0) op1 = dp[v[j-1].second];
            auto it = dp.lower_bound(p.first);
            if(it == dp.begin())
                // dp[p.second]=max(dp[p.second],2ll);
                op2 = 2ll;
            else
                // dp[p.second]=max(dp[p.second],2+(--it)->second);
                op2 = 2+(--it)->second;
            // mx = max(mx,dp[p.second]);
            dp[p.second] = max({dp[p.second], op1, op2});
            j++;
        }
        ans = min(ans,n-dp[v.back().second]);
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    cin >> tc;
    for(int ttc=1;ttc<=tc;ttc++)
        solve(ttc);
    return 0;
}