#include <iostream>
#include <fstream>

using namespace std;

int main(){

    ofstream fout ("bcount.out");
    ifstream fin ("bcount.in");


    int N, Q;
    fin>>N>>Q;

    int holst[N+1];
    int guerns[N+1];
    int jers[N+1];

    holst[0] = 0;
    guerns[0] = 0;
    jers[0] = 0;

    for(int i = 1; i <= N; i++){
        int next;
        fin>>next;
        holst[i] = holst[i-1];
        guerns[i] = guerns[i-1];
        jers[i] = jers[i-1];
        if(next == 1)
            holst[i] = holst[i-1] + 1;
        else if(next == 2)
            guerns[i] = guerns[i-1] + 1;
        else
            jers[i] = jers[i-1] + 1;
    }
    for(int i = 0; i < Q; i++){
        int a,b;
        fin>>a>>b;
        fout<<holst[b] - holst[a-1]<<" "<<guerns[b] - guerns[a-1]<<" "<<jers[b] - jers[a-1]<<endl;
    }


}