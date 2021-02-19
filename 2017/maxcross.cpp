#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ofstream fout ("maxcross.out");
    ifstream fin ("maxcross.in");
    int N,K,B;
    fin>>N>>K>>B;
    bool broken[N+1];
    int prefArr[N+1];
    prefArr[0] = 0;
    for(int i = 0; i < N+1; i++){
        broken[i] = 0;
    }    
    for(int i = 0; i < B; i++){
        int signal;
        fin>>signal;
        broken[signal] = true;
    }
    for(int i = 1; i <= N+1; i++){
        prefArr[i] = prefArr[i-1];
        if(broken[i])
            prefArr[i]++;
    }
    int minBreak = prefArr[K] - prefArr[0];
    for(int i = 0; i <= N - K; i++){
        cout<<"pos:"<<i<<"   "<<prefArr[K + i] - prefArr[i]<<endl;
        minBreak = min(prefArr[K + i] - prefArr[i],minBreak);
    }
    fout<<minBreak;
}