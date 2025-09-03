#include <bits/stdc++.h>
using namespace std;
int n, e;
int adj_matrix[1005][1005];
int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                adj_matrix[i][j] = 0;
            else
                adj_matrix[i][j] = INT_MAX;
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_matrix[a][b] = c;
        // adj_matrix[b][a]=c;   //if undirected graph
    }

    for (int k = 0; k < n; k++) //-->O(V)
    {
        for (int i = 0; i < n; i++) //-->O(V)
        {
            for (int j = 0; j < n; j++) //-->O(V)
            {
                if (adj_matrix[i][k] != INT_MAX && adj_matrix[k][j] != INT_MAX && adj_matrix[i][k] + adj_matrix[k][j] < adj_matrix[i][j])
                    adj_matrix[i][j] = adj_matrix[i][k] + adj_matrix[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_matrix[i][j] == INT_MAX)
                cout << "~ ";
            else
                cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}