#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
long long int dis[1005];
int n, e;
vector<Edge> edge_list;
bool cycle;
void belman_ford()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a = ed.a, b = ed.b, c = ed.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    cycle = false;
    for (auto ed : edge_list)
    {
        int a = ed.a, b = ed.b, c = ed.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge_list.push_back(Edge(a, b, w));
    }
    for (int i = 1; i <= n; i++)
        dis[i] = LLONG_MAX;
    int s, t, d;
    cin >> s >> t;
    dis[s] = 0;
    belman_ford();
    if (cycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        while (t--)
        {
            cin >> d;
            if (dis[d] == LLONG_MAX)
                cout << "Not Possible" << endl;
            else
                cout << dis[d] << endl;
        }
    }
    return 0;
}