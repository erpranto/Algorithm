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
int dis[1005];
int n, e;
vector<Edge> edge_list;

void belman_ford() // Time complexity -O(VE)
{
    for (int i = 0; i < n - 1; i++) //--->O(V)
    {
        for (auto ed : edge_list) //-->O(E)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
                dis[b] = dis[a] + c;
        }
    }
    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
        cout << "Negative weighted Cycle detected" << endl;
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dis[0] = 0;

    belman_ford();
    return 0;
}