#include <fstream>

using namespace std;
int main(){
    ofstream fout ("photo.out");
    ifstream fin ("photo.in");
    int N;
    
    fin>>N;
    int b[N];
    for(int i = 0; i < N; i++){
        fin>>b[i];
    }
    if(N % 2 == 1){
        int totSum = N * (N+1)/2;
        for(int i = 0; i < N; i++){
            int start = i % 2;
            while(start < N-1){
                if(start != i )
            }
        }   
    }
}