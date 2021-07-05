#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

pair<int, int> coords[100001];
vector<int> adj[100001];
bool visited[100001];
vector<int> currComponent;

void dfs(int node)
{
    if (visited[node])
    {
        return;
    }
    currComponent.push_back(node);
    visited[node] = true;
    for (int con : adj[node])
    {
        dfs(con);
    }

    // int arr[4];
    // //min x
    // int arr[0] = coords[node].first;
    // //min y
    // int arr[1] = coords[node].second;
    // //min x
    // int arr[2] = coords[node].first;
    // //min y
    // int arr[3] = coords[node].second;

    // for(int con : adj[node]){
    //     int* ptr = dfs(con);
    //     arr[0] = min(arr[0],*ptr);
    //     arr[1] = min(arr[1],*(ptr+1));
    //     arr[2] = max(arr[2],*(ptr+2));
    //     arr[3] = max(arr[3],*(ptr+3));
    // }

    // return arr;
}

int main()
{

    ofstream fout("fenceplan.out");
    ifstream fin("fenceplan.in");

    int N, M;
    fin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        int x, y;
        fin >> x >> y;
        coords[i] = {x, y};
    }
    for (int i = 0; i < M; i++)
    {
        int a, b;
        fin >> a >> b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    int minPerimeter;
    vector<vector<int>> components;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
        {
            continue;
        }
        dfs(i);
        components.push_back(currComponent);
        currComponent.clear();
    }
    int minPerm;
    for (int i = 0; i < components.size(); i++)
    {
        vector<int> nodes = components[i];
        int minX = coords[nodes[0]].first;
        int minY = coords[nodes[0]].second;
        int maxX = minX;
        int maxY = minY;
        for (int i = 1; i < nodes.size(); i++)
        {
            minX = min(minX, coords[nodes[i]].first);
            maxX = max(maxX, coords[nodes[i]].first);
            minY = min(minY, coords[nodes[i]].second);
            maxY = max(maxY, coords[nodes[i]].second);
        }
        if (i == 0)
        {
            minPerm = (maxX - minX + maxY - minY) * 2;
        }
        else
            minPerm = min(minPerm, (maxX - minX + maxY - minY) * 2);
    }
    fout << minPerm;
}