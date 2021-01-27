#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,K;
vector<pair<int,int>> adj[(int) 1e5];

bool visited[(int) 1e5];

int dfs(int node, int time){
    cout<<node;
    if(visited[node])
        return 0;
    int i = 0;
    while(i < (int) adj[node].size()){
        if(get<0>(adj[node][i]) > time)
            break;
        if(i == (int) adj[node].size() - 1)
            i = 0;
        i++;
    }
    return 1 + dfs(i,get<0>(adj[node][i]));
}

int main(){
    cin>>N>>K;
    for(int i = 0; i < K; i++){
        int first, second;
        cin>>first>>second;
        //first is the index, second is the connceted node
        adj[first - 1].push_back({i, second - 1});
        adj[second - 1].push_back({i, first - 1});
    }
    for(int i = 0; i < N; i++){
        sort(adj[i].begin(), adj[i].end());
    }

    for(int i = 0; i < N; i++){
        cout<<dfs(i, 0);
        for(int i = 0; i < N; i++)
            visited[i] = false;
    }
}