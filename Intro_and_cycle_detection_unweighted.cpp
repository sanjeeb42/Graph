#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BFS(vector<int> &visited, int i, vector<int> adj[])
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (q.empty() == false)
    {
        int top = q.front();
        cout << top << " ";
        // visited[top] = 1;
        q.pop();
        for (auto it : adj[top])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

bool Detectcycle(vector<int> &visited, int i, vector<int> adj[])
{

    // For detection of cycle , we can always try to find that the visited node is not a parent of the given

    // Node and its parent
    queue<pair<int, int>> q;
    q.push({i, -1});
    bool ans = false;
    visited[i] = true;
    while (q.empty() == false)
    {
        auto top = q.front();
        int front = top.first;
        int parent = top.second;
        q.pop();

        for (auto it : adj[front])
        {

            if ((visited[it] == true) and (parent != it))
            {
                return true;
            }
            else if (!visited[it])
            {
                q.push({it, front});
                visited[it] = true;
            }
        }
    }
    return ans;
}

void DFS(vector<int> &visited, int i, vector<int> adj[])
{
    cout << i << " ";
    visited[i] = true;
    for (auto it : adj[i])
    {

        if (!visited[it])
        {
            DFS(visited, it, adj);
        }
    }
}

bool detectcycle_DFS(vector<int> &visited, int i, vector<int> adj[], int parent)
{
    visited[i] = true;
    for (auto it : adj[i])
    {
        if (!visited[it])
        {
            if (detectcycle_DFS(visited, it, adj, i) == true)
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    //
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
    int cyc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            // BFS(visited, i, adj);
            // DFS(visited, i, adj);
            bool ans = detectcycle_DFS(visited, i, adj, -1);
            if (ans == true)
            {
                cyc = 1;
                cout << "Cycle Present" << endl;
                break;
            }
        }
    }
    if (cyc == 0)
    {
        cout << "NO Cycle" << endl;
    }
    return 0;
}
