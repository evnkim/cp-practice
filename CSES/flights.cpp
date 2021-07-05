#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> adj[100001], adjBack[100001];
bool visited[100001];

void dfs(int node)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    for (int connected : adj[node])
    {
        dfs(connected);
    }
}

void dfsBackward(int node)
{
    if (visited[node])
    {
        return;
    }
    visited[node] = true;
    for (int connected : adjBack[node])
    {
        dfsBackward(connected);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjBack[b].push_back(a);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << 1 << " " << i;
            return 0;
        }
    }
    for (int i = 0; i < 100001; i++)
    {
        visited[i] = false;
    }

    dfsBackward(1);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << i << " " << 1;
            return 0;
        }
    }
    cout << "YES";
}