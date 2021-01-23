#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("haybales.out");
    ifstream fin ("haybales.in");

    int N,Q;
    fin>>N>>Q;

    vector<int> haybales (N,0);
    for(int i = 0; i < N; i++){
        fin>>haybales[i];
    }
    sort(haybales.begin(),haybales.end());
    for(int i =0; i < Q; i++){
        int bot,top;
        fin>>bot>>top;
        auto low = lower_bound (haybales.begin(),haybales.end(),bot);
        auto up = upper_bound(haybales.begin(),haybales.end(),top);
        fout<<up - low<<endl;
    }

}