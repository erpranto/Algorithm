#include <bits/stdc++.h>
using namespace std;
bool rec(long long int n)
{
    if (n == 1)
        return true;
    if (n < 1)
        return false;
    if (n % 10 == 0 && rec(n / 10))
        return true;
    if (n % 20 == 0 && rec(n / 20))
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (rec(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}