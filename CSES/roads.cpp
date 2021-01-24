#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[static_cast<int>(1e5)];
bool visited[static_cast<int>(1e5)] = { false };

void dfs(int node){
    if(visited[node] == true)
        return;
    visited[node] = true;
    for(auto bruh : adj[node]){
        dfs(bruh);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    

    for(int i = 0; i < m; i++){
        int first,second;
        cin>>first>>second;
        adj[first - 1].push_back(second - 1);
        adj[second - 1].push_back(first - 1);
    }
    int count = 0;
    vector<int> cities;
    for(int i = 0; i < n; i++){
        if(visited[i] != true){
            dfs(i);
            cities.push_back(i);
            count++;
        }
    }
    cout<<count - 1<<endl;
    for(int i = 0; i < ((int) cities.size() ) - 1;i++){
        cout<<cities[i] + 1<<" "<<cities[i+1] + 1<<endl;
    }

}