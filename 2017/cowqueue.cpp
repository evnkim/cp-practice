#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

int main(){
    ofstream fout ("cowqueue.out");
    ifstream fin ("cowqueue.in");
    
    int N;
    fin>> N;
    vector<pair<int,int>> v;
    for(int i = 0 ; i < N; i++){
        int arrive, durr;
        //arrival
        fin>>arrive;
        //duration
        fin>>durr;
        v.push_back({arrive,durr});
    }
    
    int currTime = 0;
    sort(v.begin(), v.end());
    
    for(int i =0; i < N; i++){
        if(v[i].first > currTime)
            currTime = v[i].first;
        currTime += v[i].second;
    }
    fout<<currTime;

}