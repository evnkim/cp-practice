#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ofstream fout("lifeguards.out");
    ifstream fin("lifeguards.in");

    int N;
    fin>>N;
    vector<pair<int,int>> times;
    pair<int,int> startEnd[N+1];
    vector<int> compressedTimes;
    for(int i = 1; i < N+1; i++){
        int a,b;
        fin>>a>>b;
        times.push_back({a,i});
        times.push_back({b,-1 * i});
    }
    

    sort(times.begin(),times.end());
    for(int i = 0; i < 2 * N; i++){
        int index = abs(times[i].second);
        if(times[i].second > 0){
            startEnd[index].first = i;
        }
        else{
            startEnd[index].second = i;
        }
    }
    // compressedTimes.push_back(69);
    // for(int i = 0; i < 2 * N; i++){
    //     compressedTimes.push_back(times[i].second / abs(times[i].second));
    // }

    // typedef vector<int> Point;
    // bool ycomp(Point p, Point q) { return p[1] < q[1]; }    
    // bool xcomp(Point p, Point q) { return p[0] < q[0]; }

    // sort(compressedTimes.begin(),compressedTimes.end(),xcomp);
    // for (int i=0; i<N; i++) compressedTimes[i][0] = i+1;
    // sort(compressedTimes.begin(),compressedTimes.end(),ycomp);
    // for (int i = 0; i < N; i++) compressedTimes[i][1] = i+1;
    
    int prefSum[2 * N+2];
    int prefSumTimeAlone[2 * N + 2];
    
    //prefSum[0] = 0;
    int tot = 0;
    
    for(int i = 0; i < 2 * N; i++){
        int change;
        if(times[i].second > 0)
            change = 1;
        else
            change = -1;

        if(i == 0){
            prefSum[i] = change;

            prefSumTimeAlone[i] = 0;
        }
        else{
            prefSum[i] = prefSum[i-1] + change;

            prefSumTimeAlone[i] = prefSumTimeAlone[i-1];
            if(prefSum[i-1] == 1){
                prefSumTimeAlone[i] += times[i].first - times[i-1].first;
            }
            if(prefSum[i-1] > 0){
                tot += times[i].first - times[i-1].first;
            }
        }
        cout<<prefSum[i]<<" at "<<times[i].first<<endl;
    }
    cout<<"Total: "<<tot;
    
    
    int minTimeAlone = prefSumTimeAlone[2 * N -1];
    for(int i = 1; i < N+1; i++){
        cout<<prefSumTimeAlone[startEnd[i].second] - prefSumTimeAlone[startEnd[i].first]<<endl;
        minTimeAlone = min(minTimeAlone,prefSumTimeAlone[startEnd[i].second] - prefSumTimeAlone[startEnd[i].first]);
    }
    cout<<"Total is "<<tot<<endl;
    cout<<"subtracting from that "<<minTimeAlone<<endl;
    fout<<(tot - minTimeAlone);
    cout<<(tot - minTimeAlone);


}