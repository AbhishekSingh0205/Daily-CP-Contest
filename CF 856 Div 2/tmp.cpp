#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5, MAXQ = 1e5+5, MAXA = 1e6+5;

int n, q, a[MAXN][3], b[MAXQ][2], seg[4*MAXA][11];

void build(int node, int l, int r) {
    if (l == r) {
        for (int i = 1; i <= 10; i++) {
            seg[node][i] = (a[l][2] >= i);
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    for (int i = 1; i <= 10; i++) {
        seg[node][i] = seg[2*node][i] + seg[2*node+1][i];
    }
}

void update(int node, int l, int r, int idx, int val) {
    if (l == r) {
        for (int i = 1; i <= 10; i++) {
            seg[node][i] = (val >= i);
        }
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(2*node, l, mid, idx, val);
    } else {
        update(2*node+1, mid+1, r, idx, val);
    }
    for (int i = 1; i <= 10; i++) {
        seg[node][i] = seg[2*node][i] + seg[2*node+1][i];
    }
}

int query(int node, int l, int r, int ql, int qr, int val) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && qr >= r) return seg[node][val];
    int mid = (l + r) / 2;
    int res = query(2*node, l, mid, ql, qr, val) + query(2*node+1, mid+1, r, ql, qr, val);
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    build(1, 1, MAXA-1);

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> b[i][0] >> b[i][1];
    }
    sort(b, b+q);

    int j = 1;
    for (int i = 0; i < q; i++) {
        int pos = b[i][0], str = b[i][1];
        while (j <= n && a[j][0] <= pos) {
            update(1, 1, MAXA-1, a[j][2], 0);
            j++;
        }
        int ans = query(1, 1, MAXA-1, pos, pos, str);
        for (int k = 1; k <= 10; k++) {
            ans += query(1, 1, MAXA-1, pos-k, pos-k, str);
        }
        cout << ans << endl;
    }

    return 0;
}
