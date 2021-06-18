#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> times;

int main(){
    int N;
    for(int i = 0; i < N; i++){
        int start,end;
        cin>>start>>end;
        times.push_back({start,end});
        times.push_back({end,start});
    }
    sort(times.begin(),times.end());
    int ind = 0;
    int prefSum[times[N-1].first + 1];
    for(int i = 1; i <= times[N-1].first; i++){
        prefSum[i] = prefSum[i-1];
        if(i-1 == times[ind].first){
            
            if(times[ind].first < times[ind].second)
                prefSum[i]++;
            if(times[ind].first > times[ind].second)
                prefSum[i]++;
            ind++;
        }
    }
}