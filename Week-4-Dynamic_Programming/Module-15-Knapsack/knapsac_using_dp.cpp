#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];
int dp[1005][1005];
int knapsac(int i, int max_weight) // Time complexity --> O(NW)
{
    if (i < 0 || max_weight <= 0)
        return 0;
    if (dp[i][max_weight] != -1)
        return dp[i][max_weight];

    if (weight[i] <= max_weight)
    {
        int op1 = knapsac(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsac(i - 1, max_weight);
        dp[i][max_weight] = max(op1, op2);
        return dp[i][max_weight];
    }
    else
    {
        dp[i][max_weight] = knapsac(i - 1, max_weight);
        return dp[i][max_weight];
    }
}

int main()
{
    int n, max_weight;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];
    cin >> max_weight;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= max_weight; j++)
            dp[i][j] = -1;
    cout << knapsac(n - 1, max_weight) << endl;
    return 0;
}