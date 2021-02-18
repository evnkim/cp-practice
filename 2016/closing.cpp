#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N,M;
vector<int> adj[3001];
bool visited[3001];
vector<bool> removed(3001,false);

//breaks if 1 is removed and not connected to anything.
int dfs(int node){
    if(removed[node] && node != N)
        return dfs(node + 1);
    if(removed[node] && node == N)
        return -1;
    int count = 0;
    count++;
    visited[node] = true;
    for(int child : adj[node]){
        if(!visited[child])
            count += dfs(child);
    }
    return count;
}

int main(){
    ofstream fout ("closing.out");
    ifstream fin ("closing.in");

    fin>>N>>M;
    for(int i = 0; i < M; i++){
        int first,second;
        fin>>first>>second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    for(int i = 0; i < N; i++){
        
        if(dfs(1) < N - i)
            fout<<"NO";
        else
            fout<<"YES";
        fout<<"\n";
        int nextRemoval;
        fin>>nextRemoval;
        removed[nextRemoval] = true;
        for(int j = 1; j <= N; j++){
            if(removed[j])
                visited[j] = true;
            else{
                visited[j] = false;
            }
        }

        
    }

}