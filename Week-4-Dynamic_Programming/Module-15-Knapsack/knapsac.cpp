#include <bits/stdc++.h>
using namespace std;
int val[1005], weight[1005];

int knapsac(int i, int max_weight) // Time complexity --> O(2^N
{
    if (i < 0 || max_weight <= 0)
        return 0;
    if (weight[i] <= max_weight)
    {
        // 2 option --> rakhbo or na
        int op1 = knapsac(i - 1, max_weight - weight[i]) + val[i];
        int op2 = knapsac(i - 1, max_weight);
        return max(op1, op2);
    }
    else
    {
        // only one option
        return knapsac(i - 1, max_weight);
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
    cout << knapsac(n - 1, max_weight) << endl;
    return 0;
}