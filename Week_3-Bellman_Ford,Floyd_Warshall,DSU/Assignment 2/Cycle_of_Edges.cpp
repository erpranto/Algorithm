#include <bits/stdc++.h>
using namespace std;
int par[100005];
int group_size[100005];
int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    
    if (group_size[leaderA] >= group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));
    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA == leaderB)
            cnt++;
        else
            dsu(a, b);
    }
    cout << cnt << endl;
    return 0;
}