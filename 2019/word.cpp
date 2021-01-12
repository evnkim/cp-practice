#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream fout ("word.out");
    ifstream fin ("word.in");

    int N,K;
    fin>>N>>K;
    string words[N];
    for(int i = 0; i < N; i++){
        fin>>words[i];
    }
    
    fout<<words[0];
    int charCount = words[0].size();
    for(int i = 1; i < N; i++){
        if(charCount + words[i].size() > K){
            fout<<endl;
            fout<<words[i];
            charCount = words[i].size();
            continue;
        }
        fout<<" "<<words[i];
        charCount += words[i].size();
    }
}