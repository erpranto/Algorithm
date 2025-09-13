#include <bits/stdc++.h>
using namespace std;
bool dp[100005];
bool vis[100005];
bool rec(int n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;
    if (vis[n])
        return dp[n];

    bool res = rec(n - 3) || (n % 2 == 0 && rec(n / 2));
    dp[n] = res;
    vis[n] = true;
    return res;
}
int main()
{
    int t;
    cin >> t;
    memset(dp, false, sizeof(dp));
    memset(vis, false, sizeof(vis));

    while (t--)
    {
        int n;
        cin >> n;
        if (rec(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}