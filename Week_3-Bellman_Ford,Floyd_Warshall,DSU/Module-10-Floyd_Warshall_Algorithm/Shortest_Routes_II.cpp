#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e, q;
    cin >> n >> e >> q;
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
        long long int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = min(adj_matrix[a][b],c);
        adj_matrix[b][a] = min(adj_matrix[b][a],c);
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

    while (q--)
    {
        int s, d;
        cin >> s >> d;
        if (adj_matrix[s][d] == LLONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_matrix[s][d] << endl;
    }
    return 0;
}