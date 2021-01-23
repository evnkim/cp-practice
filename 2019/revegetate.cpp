#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    int N,M;
    ofstream fout ("revegetate.out");
    ifstream fin ("revegetate.in");
    fin>>N>>M;
    vector<int> v[N];
    int seeds[N];
    for(int i = 0; i < N; i++)
        seeds[i] = 0;
    for(int i = 0; i < M; i++){
        int first,second;
        fin>>first>>second;
        v[first -1].push_back(second - 1);
        v[second -1].push_back(first - 1);
    }
    for(int i =0; i < N; i++){
        bool store[] = {true,true,true,true};
        for(int j = 0; j < static_cast<int> (v[i].size()) ; j++){
            if(seeds[v[i][j]] > 0)
                store[seeds[v[i][j]]-1] = false;
        }
        int min = 0;
        while(!store[min]){
            min++;
        }
        seeds[i] = min + 1;
    }
    for(int i = 0; i < N; i++){
        fout<<seeds[i];
    }

}