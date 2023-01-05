#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int h = n;
        int p = m;
        n = min(h, p);
        m = max(h, p);
        int b[n * m];
        for (int i = 0; i < n * m; i++)
            cin >> b[i];
        sort(b, b + n * m);
        int x = min(n, m) - 1;
        int ch = (x + 1) / 2;
        int che = x / 2;
        int ans = INT_MAX;
        int pos = -1;
        for (int i = ch; i < n * m - che - n - m + 2; i++)
        {
            int j = i + n + m - 2;
            if (ans > b[j] - b[i])
            {
                ans = b[j] - b[i];
                pos = i;
            }
        }

        int mat[n][m];

        if (n <= m)
        {
            int k = pos;
            int l = 0;
            for (int i = 0; i < n; i++)
                mat[i][0] = b[k++];
            for (int i = 1; i < m; i++)
                mat[n - 1][i] = b[k++];
            for (int i = 0; i < n - 1; i = i + 2)
                mat[i][1] = b[l++];
            for (int i = 1; i < n - 1; i = i + 2)
                mat[i][1] = b[k++];

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 2; j < m; j++)
                {
                    if (l < pos)
                    {
                        mat[i][j] = b[l++];
                    }
                    else
                    {

                        mat[i][j] = b[k++];
                    }
                }
            }
        }
        else
        {
        }
        if (h <= p)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    cout << mat[i][j] << " ";
                cout << "\n";
            }
        }
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    cout << mat[j][i] << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}