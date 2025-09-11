#include <bits/stdc++.h>
using namespace std;
int dp[15][15];
int n, m;
int ar[15][15];
int rec(int i, int j)
{
    if (i >= n || j >= m)
        return INT_MIN;
    if (i == n - 1 && j == m - 1)
        return ar[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = rec(i, j + 1);
    int down = rec(i + 1, j);
    return dp[i][j] = ar[i][j] + max(right, down);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ar[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << rec(0, 0) << endl;
    return 0;
}