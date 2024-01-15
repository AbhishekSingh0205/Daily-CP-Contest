#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define int long long int
#define fass                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define Yes cout << "YES" << endl
#define No cout << "NO" << endl
#define random(l, r, T) uniform_int_distribution<T>(l, r)(rng) mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Segment
{
public:
    vector<int> tree;
    int size;
    Segment(int n)
    {
        size = n;
        tree.resize(4 * n, 0);
    }
    void build_tree(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            tree[ind] = 0;
            return;
        }
        int mid = (low + high) / 2;
        build_tree(2 * ind + 1, low, mid, arr);
        build_tree(2 * ind + 2, mid + 1, high, arr);
        tree[ind] = 0;
    }
    int query(int ind, int l, int r, int low, int high)
    {
        if (l > high || r < low)
        {
            return 0;
        }
        if (l <= low && r >= high)
            return tree[ind];
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, l, r, low, mid);
        int right = query(2 * ind + 2, l, r, mid + 1, high);
        int ans = left + right;
        return ans;
    }
    void update(int ind, int low, int high, int k, int val)
    {
        if (low == high)
        {
            tree[ind] += val;
            return;
        }
        cerr<<ind<<" "<<low<<" "<<high<<endl;
        int mid = (low + high) / 2;
        if (k <= mid)
        {
            update(2 * ind + 1, low, mid, k, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, high, k, val);
        }
        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }
};
signed main()
{
    // freopen("output.txt", "w", stdout);
    fass int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Segment s(n);
    s.build_tree(0, 0, n - 1, arr);
    while (q--)
    {
        int t;
        cin >> t;
        if(t==1){
            int a, b, u;
            cin >> a >> b >> u;
            s.update(0, 0, n - 1, a-1, u);
            if(b<n){
           		 s.update(0, 0, n - 1, b, -1*u); 	
            }
           
            
        }
        else{
             int x;
             cin >> x;
             cout << s.query(0, 0, x - 1, 0, n-1)+arr[x-1] << endl;
        }
    }
    return 0;
}