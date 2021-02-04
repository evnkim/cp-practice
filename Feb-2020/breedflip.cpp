#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("breedflip.out");
    ifstream fin ("breedflip.in");
    
    int N;
    string A,B;
    fin>>N>>A>>B;
    for(int i = 0; i < N; i++){
        if(A[i] == 'G'){
            if(B[i] == 'G')
                B[i] = 'H';
            else
            {
                B[i] = 'G';
            }
            A[i] = 'H';            
        }
    }
    int count = 0;
    char curr = B[0];
    if(B[0] == 'G')
        count++;
    for(int i = 1; i < N; i++){
        if(B[i] == 'G' && curr != 'G')
            count++;
        curr = B[i];
    }
    fout<<count;
}