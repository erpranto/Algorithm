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
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        if(n<0)
        {
            cout<<"0 0"<<endl;
            continue;
        }
        vector<int> v2 = v;
        sort(v2.rbegin(), v2.rend());
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++)
        {
            if (v2[0] == v[i] && idx1 == -1)
                idx1 = i;
            if (v2[1] == v[i] && idx2 == -1)
                idx2 = i;
        }

        cout << min(idx1, idx2) << " " << max(idx1, idx2) << endl;
    }
    return 0;
}