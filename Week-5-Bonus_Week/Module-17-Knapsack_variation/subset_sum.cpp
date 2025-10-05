#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int val[1005];

bool subset_sum(int i, int sum) // O(2^N)
{
    if (i < 0)
    {
        if (sum == 0)
            return true;
        else
            return false;
    }
    if (val[i] <= sum)
    {
        bool op1 = subset_sum(i - 1, sum - val[i]);
        bool op2 = subset_sum(i - 1, sum);
        return op1 || op2;
    }
    else
        return subset_sum(i - 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int sum;
    cin >> sum;

    if (subset_sum(n, sum))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}