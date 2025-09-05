#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e;
    long long int adj_matrix[n + 5][n + 5];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = LLONG_MAX;
        }
    }

    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        adj_matrix[a][b] = min(adj_matrix[a][b], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj_matrix[i][k] != LLONG_MAX && adj_matrix[k][j] != LLONG_MAX && adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
            }
        }
    }
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (adj_matrix[x][y] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matrix[x][y] << endl;
    }
    return 0;
}