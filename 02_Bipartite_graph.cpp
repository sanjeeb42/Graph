#include <bits/stdc++.h>
using namespace std;

bool color_graph_BFS(int i, vector<int> adj[], vector<int> &color)
{
    // Do a BFS
    queue<int> q;
    q.push(i);
    color[i] = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto it : adj[front])
        {
            if (color[it] != -1)
            {
                if (color[it] == color[front])
                {
                    return false;
                }
            }
            else
            {
                q.push(it);
                color[it] = 1 - color[front];
            }
        }
    }

    return true;
}

bool color_graph_DFS(int i, vector<int> adj[], vector<int> &color)
{
    if (color[i] == -1)
    {
        color[i] = 1;
    }
    for (auto it : adj[i])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[i];
            if (!color_graph_DFS(it, adj, color))
            {
                return false;
            }
        }
        else if (color[it] == color[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> colour(n + 1, -1);

    for (int i = 1; i <= n; i++)
    {

        if (colour[i] == -1)
        {
            // bool ans = color_graph_BFS(1, adj, colour);
            bool ans = color_graph_DFS(1, adj, colour);

            if (!ans)
            {
                cout << "No" << endl;
                break;
            }
        }
        if (i == n)
        {
            cout << "Yes" << endl;
        }
    }
}
