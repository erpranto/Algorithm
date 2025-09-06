#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i;
        for (i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                break;
        }
        if (s[i - 1] == 'a')
            s.insert(s.begin() + i, 'b');
        else
            s.insert(s.begin() + i, 'a');
        cout << s << endl;
    }
    return 0;
}