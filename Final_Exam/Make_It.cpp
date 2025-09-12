#include <bits/stdc++.h>
using namespace std;
long long int dp[100005];
bool rec(long long int n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;
    if (dp[n] != -1)
        return dp[n] == 2;

    bool res = false;
    if (rec(n - 3) || n % 2 == 0 && rec(n / 2))
    {
        res = true;
        dp[n] = 2;
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));

        if (rec(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}