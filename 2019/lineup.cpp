/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: evan.e.1
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    int N;
    string dummy;

    vector<string> cows[8] = {"Beatrice","Belinda", "Bella","Bessie", "Betsy", "Blue","Buttercup","Sue"};

    fin>>N;
    string conditions[N][2];

    for(int i = 0; i < N; i++){
        fin>>conditions[i][0]>>dummy>>dummy>>dummy>>dummy>>conditions[i][1];
    }


    fout<<conditions[1][1];
    return 0;
}