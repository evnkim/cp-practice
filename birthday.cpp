#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];
vector<pair<int, int>> connections;
int removed1, removed2;

void resetArrs()
{
    for (int i = 0; i < 101; i++)
    {
        visited[i] = false;
        vector<int> bruh;
        adj[i] = bruh;
    }
    connections.clear();
}

bool connected(int N)
{
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

void dfs(int node)
{
    if (visited[node])
        return;
    visited[node] = true;
    for (int connected : adj[node])
    {
        if ((node == removed1 && connected == removed2) || (node == removed2 && connected == removed1))
        {
            continue;
        }
        dfs(connected);
    }
}

int main()
{
    while (true)
    {
        resetArrs();
        int p, c;
        cin >> p >> c;
        if (p == 0 && c == 0)
        {
            break;
        }

        for (int i = 0; i < c; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            connections.push_back({a, b});
        }
        if (c <= p - 1)
        {
            cout << "Yes" << endl;
            continue;
        }

        bool no = false;
        for (auto edge : connections)
        {
            for (int i = 0; i < 101; i++)
            {
                visited[i] = false;
            }
            removed1 = edge.first;
            removed2 = edge.second;
            dfs(0);
            if (!connected(p))
            {
                cout << "Yes" << endl;
                no = true;
                break;
            }
        }
        if (no)
        {
            continue;
        }
        cout << "No" << endl;
    }

    return 0;
}