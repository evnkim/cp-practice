#include <iostream>
#include <set>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("whereami.out");
    ifstream fin ("whereami.in");


    int N;
    fin>>N;
    string s;
    fin>>s;
    for(int i = 1; i < N; i++){
        set<string> seqs;
        for(int j = 0; j < N - i + 1; j++){
            seqs.insert(s.substr(j,i));
        }
        if((int) seqs.size() == N - i + 1){
            fout<<i;
            return 0;
        }
    }
    fout<<N;
}