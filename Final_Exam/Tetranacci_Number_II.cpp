#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    long long int tn[n + 1];
    tn[0] = 0;
    tn[1] = 1;
    tn[2] = 1;
    tn[3] = 2;
    for (long long int i = 4; i <= n; i++)
    {
        tn[i] = tn[i - 1] + tn[i - 2] + tn[i - 3] + tn[i - 4];
    }
    cout << tn[n] << endl;
    return 0;
}