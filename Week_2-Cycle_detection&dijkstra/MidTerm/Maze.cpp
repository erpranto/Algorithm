//Maze 
#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int row, col;

bool valid(int i, int j)
{
    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int pi = par.first;
        int pj = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = pi + d[i].first;
            int cj = pj + d[i].second;
            if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
                parent[ci][cj] = {pi, pj};
            }
        }
    }
}

int main()
{
    cin >> row >> col;
    int si, sj, di, dj;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            parent[i][j] = {-1, -1};
            if (grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            parent[i][j] = {-1, -1};

    bfs(si, sj);

    if (vis[di][dj] == true)
    {
        int node_i = di, node_j = dj;
        while (true)
        {
            pair<int, int> par = parent[node_i][node_j];
            node_i = par.first;
            node_j = par.second;
            if (grid[node_i][node_j] == 'R')
            {
                break;
            }
            grid[node_i][node_j] = 'X';
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}