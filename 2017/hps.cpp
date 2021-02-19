#include <iostream>
#include <fstream>
#include <algorithm>
#include <array>

using namespace std;

int main(){
    ofstream fout ("hps.out");
    ifstream fin ("hps.in");
    int N;
    fin>>N;
    
    //0 hoof wins, 1 paper wins, 2 scissor wins
    int prefArr[N+1][3];
    for(int i = 0; i < N+1; i++){
        prefArr[i][0] = 0;
        prefArr[i][1] = 0;
        prefArr[i][2] = 0;
    }
    for(int i = 1; i <= N; i++){
        char move;
        fin>>move;
        prefArr[i][2] = prefArr[i-1][2];
        prefArr[i][1] = prefArr[i-1][1];
        prefArr[i][0] = prefArr[i-1][0];
        if(move == 'P')
            prefArr[i][2]++;
        else if(move == 'H')
            prefArr[i][1]++;
        else
            prefArr[i][0]++;
        cout<<"Currently at "<<i<<endl;
        cout<<prefArr[i][2]<<" "<<prefArr[i][1]<<" "<<prefArr[i][0]<<" "<<endl;
        
    }
    cout<<prefArr[N][0]<<endl;
    cout<<prefArr[N][1]<<endl;
    cout<<prefArr[N][2]<<endl;
    int maxWin = prefArr[N][0];
    for(int i = 0; i <= N; i++){
        int possibleVals1[3];
        int possibleVals2[3];
        possibleVals1[0]=  prefArr[i][0] - prefArr[0][0];
        possibleVals2[0]= prefArr[N][0] - prefArr[i][0];
        possibleVals1[1]=  prefArr[i][1] - prefArr[0][1];
        possibleVals2[1]= prefArr[N][1] - prefArr[i][1];
        possibleVals1[2]=  prefArr[i][2] - prefArr[0][2];
        possibleVals2[2]= prefArr[N][2] - prefArr[i][2];
        
        int maxThisRound = possibleVals1[0];
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                maxThisRound = max(maxThisRound,possibleVals1[j] + possibleVals2[k]);
            }
        }

        maxWin = max(maxWin, maxThisRound);
    }
    fout<<maxWin;

}