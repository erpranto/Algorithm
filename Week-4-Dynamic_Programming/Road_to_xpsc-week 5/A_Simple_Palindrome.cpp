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
        vector<char> v = {'a', 'e', 'i', 'o', 'u'};
        string ans = "";
        int i = 0;
        while (n--)
        {
            ans += v[i];
            i++;
            if (i == 5)
                i = 0;
        }
        sort(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}