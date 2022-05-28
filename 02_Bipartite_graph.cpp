#include <bits/stdc++.h>
using namespace std;

bool color_graph(int i, vector<int> adj[], vector<int>&color)
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
            bool ans = color_graph(1, adj, colour);

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
