#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for (char c : s)
            if (c == '1')
                cnt++;
        int ans = 0;
        for (char c : s)
        {
            if (c == '1')
                ans += cnt - 1;
            else
                ans += cnt + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
