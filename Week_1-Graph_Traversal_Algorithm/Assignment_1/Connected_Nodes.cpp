#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1000005];
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int node;
        cin >> node;
        vector<int> v;
        if (!adj_list[node].empty())
        {
            for (int i : adj_list[node])
            {
                v.push_back(i);
            }
            sort(v.rbegin(), v.rend());
            for (int i : v)
                cout << i << " ";
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}