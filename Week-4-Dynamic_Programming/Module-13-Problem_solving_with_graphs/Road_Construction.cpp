#include <bits/stdc++.h>
using namespace std;
int n, m;
int par[100005];
int group_size[100005];
int cmp, mx;

int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void dsu_union(int node1, int node2)
{
    int leaderA = find(node1);
    int leaderB = find(node2);
    if(leaderA==leaderB)
        return ;
    if (group_size[leaderA] >= group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
        mx = max(mx, group_size[leaderA]);
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
        mx = max(mx, group_size[leaderB]);
    }
    cmp--;
}
int main()
{
    cin >> n >> m;
    cmp = n;
    mx = 1;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        dsu_union(a, b);
        cout << cmp << " " << mx << endl;
    }
    return 0;
}