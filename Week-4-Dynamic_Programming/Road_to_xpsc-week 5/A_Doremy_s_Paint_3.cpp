#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        if (mp.size() > 2)
            cout << "No\n";
        else
        {
            if (mp.size() == 2)
            {
                vector<int> v;
                for (auto p : mp)
                {
                    v.push_back(p.second);
                }
                if (abs(v[0] - v[1]) > 1)
                    cout << "No\n";
                else
                    cout << "Yes\n";
            }
            else
                cout << "Yes\n";
        }
    }
    return 0;
}