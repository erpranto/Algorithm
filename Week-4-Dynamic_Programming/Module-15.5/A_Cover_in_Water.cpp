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
        int cnt = 0, water = 0;
        for (char c : s)
        {
            if (c == '.')
            {
                water++;
                cnt++;
                if (cnt == 3)
                    break;
            }
            if (c == '#')
                cnt = 0;
        }
        if (cnt == 3)
            cout << 2 << endl;
        else
            cout << water << endl;
    }
    return 0;
}