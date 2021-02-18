#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<pair<int,int>> adj[101];
bool visited[101];
int N;

bool dfs(int node){
    cout<<node;
    visited[node] = true;
    for(pair<int,int> connected : adj[node]){
        if(visited[connected.first])
            continue;
        if(connected.second == -1)
            return false;
        if(!dfs(connected.first))
            return false;
    }
    return true;
}

int main(){
    ofstream fout ("factory.out");
    ifstream fin ("factory.in");
    fin>>N;
    for(int i = 1; i < N + 1; i++){
        int first, second;
        fin>>first>>second;
        adj[second].push_back({first,1});
        adj[first].push_back({second,-1});
    }
    for(int i = 1; i < N; i++){
        if(dfs(i)){
            fout<<i;
            return 0;
        }
        for(int j = 0; j < 101; j++){
            visited[j] = false;
        }
    }
    fout<<"-1";
}