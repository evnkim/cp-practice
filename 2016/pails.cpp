#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    //X < Y < M
    int X,Y,M;

    ofstream fout ("pails.out");
    ifstream fin ("pails.in");

    fin>>X>>Y>>M;

    int numY = M / Y;
    int maxVal = 0;
    while(numY >= 0){
        maxVal = max(maxVal,M - ((M - numY * Y) % X));
        numY--;
    }
    fout<<maxVal;
}