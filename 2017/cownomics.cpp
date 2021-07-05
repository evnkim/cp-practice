#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N,M;

string seq[1000];
set<int> poss;

// bool checkDiff(int ind1,int ind2, int ind3){
//     for(int i=  0; i < N; i++){
//         for(int j = N; j < 2 * N; j++){
//             if(seq[i][ind1] == seq[j][ind1] && seq[i][ind2] == seq[j][ind2] && seq[i][ind3] == seq[j][ind3])
//                 return false;
//         }
//     }
//     return true;
// }

int getNum(char c){
    if(c == 'A'){
        return 0;
    }
    if(c == 'C'){
        return 1;
    }
    if(c == 'G'){
        return 2;
    }
    return 3;
}

int getThree(int i, int ind1, int ind2, int ind3){
    int bruh = 0;
    bruh += getNum(seq[i][ind1]);
    bruh += getNum(seq[i][ind2]) * 4;
    bruh += getNum(seq[i][ind3]) * 16;
    return bruh;
}

void fillPoss(int ind1, int ind2, int ind3)
{
    for (int i = 0; i < N; i++)
    {
       poss.insert(getThree(i,ind1,ind2,ind3));
    }
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
                fillPoss(i,j,k);
                bool works = true;
                for(int x = N; x < 2*N; x++){
                    if(poss.count(getThree(x,i,j,k)) > 0){
                        works = false;
                        break;
                    }
                }
                if(works)
                    count++;
                poss.clear();
            }
        }
    }
    fout<<count;
}