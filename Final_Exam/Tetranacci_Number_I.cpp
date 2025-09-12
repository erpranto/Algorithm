#include <bits/stdc++.h>
using namespace std;
int dp[35];
long long int tetranacci(long long int n)
{
    if (n < 2)
        return n;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    if (dp[n] != 0)
        return dp[n];
    return dp[n] = tetranacci(n - 1) + tetranacci(n - 2) + tetranacci(n - 3) + tetranacci(n - 4);
}

int main()
{
    memset(dp, 0, sizeof(dp));
    long long int n;
    cin >> n;
    cout << tetranacci(n) << endl;
    return 0;
}