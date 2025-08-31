//Same_Compon
#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < d.size(); i++)
    {
        int ci, cj;
        ci = si + d[i].first;
        cj = sj + d[i].second;
        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    memset(vis, false, sizeof(vis));

    int sx, sy, dx, dy;
    cin >> sx >> sy;
    cin >> dx >> dy;

    if (grid[sx][sy] == '-' || grid[dx][dy] == '-')
    {
        cout << "NO\n";
        return 0;
    }
    
    dfs(sx, sy);

    if (vis[dx][dy])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}