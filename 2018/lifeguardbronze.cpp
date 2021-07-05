#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ofstream fout("lifeguards.out");
    ifstream fin("lifeguards.in");

    int N;
    pair<int,int> times[100];
    fin>>N;
    
    for(int i = 0; i < N; i++){
        int start, end;
        fin>>start>>end;
        times[i] = {start,end};
    }
    int maxCount = 0;
    for(int j = 0; j< N; j++){
        int changes[1001];
        int prefSum[1001];
        for(int i = 0; i < 1001; i++){
            changes[i] = 0;
            prefSum[i] = 0;
        }
        for(int i = 0; i < N; i++){
            if(i == j)
                continue;
            changes[times[i].first]++;
            changes[times[i].second]--;
        }
        int count = 0;
        for(int i = 0; i < 1001; i++){
            if(i == 0){
                prefSum[i] = changes[i];
            }
            else{
                prefSum[i] = prefSum[i-1] + changes[i];
            }
            if(prefSum[i] > 0){
                count++;
            }
        }
        maxCount = max(maxCount,count);
    }
    fout<<maxCount;
}