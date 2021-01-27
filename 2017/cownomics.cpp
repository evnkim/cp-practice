#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int N,M;

string seq[1000];

bool checkDiff(int ind1,int ind2, int ind3){
    for(int i=  0; i < N; i++){
        for(int j = N; j < 2 * N; j++){
            if(seq[i][ind1] == seq[j][ind1] && seq[i][ind2] == seq[j][ind2] && seq[i][ind3] == seq[j][ind3])
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
    for(int i = 0; i < M - 2; i++){
        for(int j = i + 1; j < M-1; j++){
            for(int k = j+1; k < M; k++){
                if(checkDiff(i,j,k))
                    count++;
            }
        }
    }
    fout<<count;
}