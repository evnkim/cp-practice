#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int N;
vector<int> adj[(int) 1e5];
bool visited[(int) 1e5];


int solve(int node){
    visited[node] = true;
    int total = 0;
    int deg = adj[node].size();
    if(node != 0){
        int takeLog = (int) log2(deg);
        if(deg != (int) pow(2.0,takeLog))
            takeLog++;
        total += takeLog;
        total += deg - 1;
    }
    else{
        int takeLog = (int) log2(deg + 1);
        if(deg + 1 != (int) pow(2.0,takeLog))
            takeLog++;
        total += takeLog;
        total += deg;
    }


    for(int connected : adj[node]){
        if(!visited[connected]){
            total += solve(connected);
        }
    }
    return total;
}

int main(){
    cin>>N;
    for(int i = 0; i < N -1; i++){
        int first, second;
        cin>>first>>second;
        adj[first - 1].push_back(second - 1);
        adj[second - 1].push_back(first - 1);
    }
    for(int i = 0; i < N; i++){
        visited[i] = false;
    }
    cout<<solve(0);
}