#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
void bfs(int src) 
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " ";
        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}
// Time Complexity O(v+e)/O(n+e)
// Space Complexity O(v)/O(n)

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
    memset(vis, false, sizeof(vis));
    bfs(0);
    return 0;
}