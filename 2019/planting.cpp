#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("planting.out");
    ifstream fin ("planting.in");
    int N;
    fin>>N;
    vector<int> adj[N];
    for(int i = 0; i < N-1; i++){
        int first,second;
        fin>>first>>second;
        adj[first - 1].push_back(second - 1);
        adj[second - 1].push_back(first - 1);
    }
    int maxDeg = 0;
    for(int i = 0; i < N; i++){
        maxDeg = max( (int) adj[i].size(),maxDeg);
    }
    fout<<maxDeg + 1;

}