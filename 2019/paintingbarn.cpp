#include<iostream>
#include<fstream>


using namespace std;
int prefSum[1002][1002] = {0};

int main(){

    ofstream fout ("paintbarn.out");
    ifstream fin ("paintbarn.in");

    cout<<"wtf hello";
    int N, K;
    cout<<"wtf hello";
    fin>>N>>K;
    cout<<"afjsadjfsadjfasdf";
   
    //int bruh[1001][1001];
    
    
    for(int i = 0; i < N; i++){
        int x1,y1,x2,y2;
        fin>>x1>>y1>>x2>>y2;
        x1++;
        y1++;
        x2++;
        y2++;
        prefSum[x1][y1]++;
        prefSum[x1][y2]--;
        prefSum[x2][y1]--;
        prefSum[x2][y2]++;
    }
    int count = 0;
    for(int i = 1; i < 1002; i++){
        for(int j = 1; j < 1002; j++){
            prefSum[i][j] = prefSum[i-1][j] + prefSum[i][j-1] + prefSum[i][j] - prefSum[i-1][j-1];
            if(prefSum[i][j] == K){
                count++;
            }
        }
    }
    fout<<count;
}