#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int N;
vector<pair<int,int>> peaks;
bool visible[100000];

int main(){
    ofstream fout("mountains.out");
    ifstream fin("mountains.in");

    fin>>N;
    for(int i = 0; i < N; i++){
        int x,y;
        fin>>x>>y;
        peaks.push_back({x,y});
        visible[i] = true;
    }
    sort(peaks.begin(),peaks.end());
    for(int i = 0; i < N; i++){
        int x = peaks[i].first;
        int y = peaks[i].second;
        for(int j = i-1; j >= 0; j--){
            if(peaks[j].second > y - (x - peaks[j].first)){
                break;
            }
            else{
                visible[j] = false;
            }
        }
        for(int j = i+1; j < N; j++){
            if(peaks[j].second > y - (peaks[j].first - x)){
                break;
            }
            else{
                visible[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 0; i < N ;i++){
        if(visible[i]){
            count++;
        }
    }
    fout<<count;
}