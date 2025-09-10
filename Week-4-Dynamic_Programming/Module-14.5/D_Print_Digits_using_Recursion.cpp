#include <bits/stdc++.h>
using namespace std;
void prnt(int n)
{
    if (n< 10)
    {
        cout << n << " ";
        return;
    }
    int x = n % 10;
    prnt(n / 10);
    cout << x << " ";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        prnt(n);
        cout << endl;
    }
    return 0;
}