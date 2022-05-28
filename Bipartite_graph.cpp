#include <bits/stdc++.h>
using namespace std;

bool color_graph(vector<int> &visited, int i, vector<int> adj[], vector<int> color)
{
    // Do a BFS
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    int colour = 0;
    color[i] = colour;
    colour = !colour;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        colour = !color[front];
        for (auto it : adj[front])
        {
            if (visited[it])
            {
                if (color[it] == color[front])
                {
                    cout << "for " << front << " and " << it << endl;
                    return false;
                }
            }
            else
            {
                q.push(it);
                visited[it] = true;
                color[it] = colour;
            }
        }
        //colour = !colour;

        for (auto it : color)
        {
            cout << it << " ";
        }
        cout << endl;
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

    vector<int> visited(n + 1, 0);
    vector<int> colour(n + 1, -1);

    bool ans = color_graph(visited, 1, adj, colour);

    cout << ans << endl;
}
