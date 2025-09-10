#include <bits/stdc++.h>
using namespace std;
long long int dp[1005];

long long int fibo(long long int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main()
{
    long long int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << fibo(n);
    return 0;
}