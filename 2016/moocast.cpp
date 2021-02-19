#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <array>

using namespace std;

vector<int> adj[200];
array<bool,200> visited;

int dfs(int node){
    cout<<node<<endl;
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
    ofstream fout ("moocast.out");
    ifstream fin ("moocast.in");
    
    int N;
    fin>>N;
    int info[N][3];
    for(int i = 0; i < N; i++){
        fin>>info[i][0]>>info[i][1]>>info[i][2];
    }
    for(int i = 0; i < N; i++){
        int pow=  info[i][2];
        int x = info[i][0];
        int y = info[i][1];
        for(int j = 0; j < N; j++){
            if(j == i)
                continue;
            if((info[j][0] - x) * (info[j][0] - x) + (info[j][1] - y) * (info[j][1] - y) < pow * pow){
                adj[i].push_back(j);
            } 
        }
    }

    int maxBroad=  0;
    for(int i = 0; i < N; i++){
        cout<<"-----------------\n"<<"Starting from "<<i<<endl;
        maxBroad = max(maxBroad, dfs(i));
        visited.fill(false);
    }
    fout<<maxBroad;

}