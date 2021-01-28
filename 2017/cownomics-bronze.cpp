#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int N,M;

string seq[1000];

bool checkDiff(int ind1){
    for(int i=  0; i < N; i++){
        for(int j = N; j < 2 * N; j++){
            if(seq[i][ind1] == seq[j][ind1])
                return false;
        }
    }
    return true;
}

int main(){
    ofstream fout ("cownomics.out");
    ifstream fin ("cownomics.in");

    fin>>N>>M;

    for(int i  = 0; i < 2 * N; i++){
        fin>>seq[i];
    }
    int count = 0;
    for(int i = 0; i < M ; i++){
        if(checkDiff(i))
            count++;
    }
    fout<<count;
}