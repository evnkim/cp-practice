#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ofstream fout("diamond.out");
    ifstream fin("diamond.in");
    
    int N,K;
    fin>>N>>K;

    int sizeArr[N];
    for(int i = 0; i < N; i++){
        fin>>sizeArr[i];
    }
    sort(sizeArr,sizeArr + N);
    int maxCount = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        int j=0;
        //right
        while(i + j < N && sizeArr[i+j] -sizeArr[i] <= K){
            count++;
            j++;
        }
        maxCount = max(maxCount,count);
    }
    fout<<maxCount;
}