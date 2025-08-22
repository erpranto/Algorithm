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
    }
    int q;
    cin >> q;
    while (q--)
    {
        int node, src;
        cin >> node >> src;
        if (node == src)
            cout << "YES" << endl;
        else
        {
            vector<int> v;
            bool f = false;

            for (int i : adj_list[node])
            {
                if (i == src)
                {
                    f = true;
                    break;
                }
            }
            if (f == true)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}