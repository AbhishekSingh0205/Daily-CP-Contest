#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
#define endl '\n'

vector<vector<ll>> dp;
vector<int> a, b;
int n, m, k;

void solve() { // O(N*M) Time, O(N) space.
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++)cin >> b[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1e18));
    dp[1][0] = 0;
    ll ans = 1e18;
    for (int j = 0; j <= m; j++) {
        deque<int> dq;
        dq.push_front(1);
        for (int i = 2; i <= n; i++) {
            dp[i][j & 1] = min(dp[i][j & 1], dp[i - 1][j & 1] + a[i - 1]);
            if (j == 0)continue;
            while (!dq.empty() && dq.front() < i - k)dq.pop_front();
            dp[i][j & 1] = min(dp[i][j & 1], dp[dq.front()][(j - 1) & 1] + b[dq.front()] + b[i]);
            while (!dq.empty() && dp[dq.back()][(j - 1) & 1] + b[dq.back()] >= dp[i][(j - 1) & 1] + b[i])dq.pop_back();
            dq.push_back(i);
        }
        ans = min(ans, dp[n][j & 1]);
    }
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
