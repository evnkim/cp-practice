#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

pair<int,int> coords[1001];

bool ycomp(pair<int,int> p, pair<int,int> q){
    return p.second < q.second;
}

int main() {
    ofstream fout("balancing.out");
    ifstream fin("balancing.in");


    int N,B;
    fin>>N;

    for(int i = 0; i < N; i++){
        int x,y;
        fin>>x>>y;
        coords[i] = {x,y};
    }

    sort(coords, coords + N);
    int prevX = coords[0].first;
    coords[0].first = 1;
    int x = 1;
    for(int i = 1; i < N; i++){
        if(coords[i].first == prevX){
            prevX = coords[i].first;
            coords[i].first = x;
        }
        else{
            prevX = coords[i].first;
            x += 2;
            coords[i].first = x;
        }
        
    }

    int maxX = coords[N-1].first;

    sort(coords,coords + N, ycomp);
    int prevY = coords[0].second;
    coords[0].second = 1;
    int y = 1;
    for(int i = 1; i < N; i++){
        if(coords[i].second == prevY){
            prevY = coords[i].second;
            coords[i].second = y;
        }
        else{
            prevY = coords[i].second;
            y += 2;
            coords[i].second = y;
        }
        
    }

    for(int i = 0; i < N; i++){
        cout<<coords[i].first<<","<<coords[i].second<<endl;
    }

    int M;

    int prefSum[maxX + 4][coords[N-1].second + 4];
    for(int i = 0; i < maxX + 4; i++){
        for(int j= 0 ; j < coords[N-1].second + 4; j++){
            prefSum[i][j] = 0;
        }
    }
    for(int i = 0; i < N; i++){
        prefSum[coords[i].first][coords[i].second]++;
    }
    for(x = 1; x < maxX + 4; x++){
        for(y = 1; y < coords[N-1].second + 4; y++){
            prefSum[x][y] = prefSum[x][y] + prefSum[x-1][y] + prefSum[x][y-1] - prefSum[x-1][y-1];
        }
    }

    int topX = maxX + 3;
    int topY = coords[N-1].second + 3;

    for(int x = 0; x <= maxX + 3; x += 2){
        for(int y = 0; y <= coords[N-1].second + 3; y += 2){
            int I=0; int II=0; int III = 0; int IV = 0;
            I = prefSum[topX][topY] - prefSum[topX][y] - prefSum[x][topY] + prefSum[x][y];
            II = prefSum[x][topY] - prefSum[x][y];
            III = prefSum[x][y];
            IV = prefSum[topX][y] - prefSum[x][y];
            if(x == 0 && y == 0)
                M = max(max(I,II),max(III,IV));
            else
                M = min(M,max(max(I,II),max(III,IV)));
        }
    }
    fout<<M;
}