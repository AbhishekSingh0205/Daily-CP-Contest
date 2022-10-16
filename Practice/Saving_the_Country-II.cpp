// Author : Abhishek Singh
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ll int
#define pb push_back
#define fl(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
#define e1(a) \
    int a;    \
    cin >> a;
#define e2(a, b) \
    int a, b;    \
    cin >> a >> b;
#define rz resize
#define vvi vector<vector<int>>
#define sz(s) s.size()
#define mod 1000000007
#define ff first
#define ss second
#define inf 10e15
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>

const int N = 1e5 + 5;

map<int, set<int>> m;
map<int, int> freq;
vector<pii> gr[N];
vector<int> ans;
vector<pii> qry[N];

template <typename Node, typename Update>
struct SegTree
{
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a)
    { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        tree.resize(s);
        fill(all(tree), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) // Never change this
    {
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u) // Never Change this
    {
        if (start == end)
        {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val)
    {                                    // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right)
    {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1
{
    ll val; // may change
    Node1()
    {             // Identity element
        val = -1; // may change
    }
    Node1(ll p1)
    {             // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                            // Merge two child nodes
        val = max(l.val, r.val); // may change
    }
};

struct Update1
{
    ll val; // may change
    Update1(ll p1)
    {             // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a)
    {                // apply update to given node
        a.val = val; // may change
    }
};

vector<ll> V(N, -1);
void init()
{
    m.clear();
    freq.clear();
    for (int i = 0; i < N; i++)
    {
        gr[i].resize(0);
    }
    ans.clear();
    for (int i = 0; i < N; i++)
    {
        qry[i].resize(0);
    }
    V.resize(N, -1);
}

void dfs(int src, int pare, SegTree<Node1, Update1> &sg)
{
    // Answering for each query realated to node :->src
    for (auto v : qry[src])
    {
        ans[v.ss] = sg.make_query(v.ff, N - 1).val;
    }
    for (auto v : gr[src])
    {
        if (v.ff != pare)
        {
            int original = 0;
            if (freq.find(v.ss) == freq.end())
            {
                freq[v.ss] = 1;
            }
            else
            {
                original = freq[v.ss];
                freq[v.ss]++;
            }
            if (original)
            {
                auto it = m[original].find(v.ss);
                m[original].erase(it);
                if (m[original].size() != 0)
                {
                    sg.make_update(original, *(m[original].rbegin()));
                }
                else
                {
                    sg.make_update(original, -1);
                }
            }
            m[freq[v.ss]].insert(v.ss);
            sg.make_update(freq[v.ss], *(m[freq[v.ss]].rbegin()));
            dfs(v.ff, src, sg);
            original = freq[v.ss];
            int newFreq = original - 1;
            freq[v.ss] = newFreq;
            m[original].erase(v.ss);

            if (m[original].size() != 0)
            {
                sg.make_update(original, *(m[original].rbegin()));
            }
            else
            {
                sg.make_update(original, -1);
            }
            if (newFreq)
            {
                m[newFreq].insert(v.ss);
                sg.make_update(newFreq, *(m[newFreq].rbegin()));
            }
        }
    }
}
void solve()
{
    init();
    SegTree<Node1, Update1> sg = SegTree<Node1, Update1>(sz(V), V);
    e2(n, q);
    ans.resize(q + 1);
    for (int i = 0; i < n - 1; i++)
    {
        e2(x, y);
        x--;
        y--;
        e1(w);
        gr[x].pb({y, w});
        gr[y].pb({x, w});
    }
    for (int i = 0; i < q; i++)
    {
        e2(x, k);
        x--;
        qry[x].pb({k, i});
    }
    dfs(0, -1, sg);
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    fl(i, 1, t + 1)
    {
        solve();
    }
    return 0;
}