#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> freq(26, 0);
        for (char c : s1)
            freq[c - 'a']++;
        for (char c : s2)
            freq[c - 'a']--;
        bool flag = true;
        for (auto f : freq)
        {
            if (f != 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}