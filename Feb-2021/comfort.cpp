#include <iostream>
#include <vector>

using namespace std;

bool cows[100000][100000];
vector<pair<int,int>> cowCoords;
int N;

int computeMin(){
    int tot = 0;
    for(pair<int,int> coords : cowCoords){
        int count = 0;
        if((coords.second - 1 >= 0) && cows[coords.first][coords.second - 1])
            count++;
        if((coords.first - 1 >= 0) && cows[coords.first - 1][coords.second])
            count++;
        if((coords.first + 1 < 100000) && cows[coords.first + 1][coords.second])
            count++;
        if((coords.second + 1 < 100000) && cows[coords.first][coords.second + 1])
            count++;
        if(count != 3){
            tot += 0;
        }

    }
}

int main(){
    cin>>N;
    for(int i = 0; i < N){
        int x,y;
        cin>>x>>y;
        cows[x][y] = true;
        cowCoords.push_back({x,y});
        cout<<computeMin();

    }
}