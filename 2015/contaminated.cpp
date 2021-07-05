#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ofstream fout("badmilk.out");
    ifstream fin("badmilk.in");

    int N,M,D,S;
    fin>>N>>M>>D>>S;
    
    vector<int> milkDrank[N+1][101];

    for(int i = 0; i < D; i++){
        int p, m, t;
        fin>>p>>m>>t;
        milkDrank[p][t].push_back(m);
    }

    set<int> possibleMilk;
    for(int i = 0; i < S; i++){
        int p,t;
        fin>>p>>t;
        if(i == 0){
            for(int j = 1; j < t; j++){
                for(int milk : milkDrank[p][j]){
                    possibleMilk.insert(milk);
                }
            }
        }
        else{
            set<int> milks;
            for(int j = 1; j < t; j++){
                for(int milk : milkDrank[p][j])
                    milks.insert(milk);
            }
            set<int> toBeRemoved;
            for(int milk : possibleMilk){
                if(milks.count(milk) == 0){
                    toBeRemoved.insert(milk);
                }
            }
            for(int remove : toBeRemoved){
                possibleMilk.erase(remove);
            }
        }
    }

    int milkNums[M+1];
    for(int i = 0; i < M+1; i++){
        milkNums[i] = 0;
    }
    for(int i = 1; i <= N; i++){
        set<int> milks;
        for(int t = 1; t < 101; t++){
            
            for(int m : milkDrank[i][t])
                milks.insert(m);
            
        }
        for(int possible : possibleMilk){
            if(milks.count(possible) > 0){
                milkNums[possible]++;
            }
        }
    }
    int maxNeeded = 0;
    for(int i = 0; i < M+1; i++){
        maxNeeded = max(maxNeeded, milkNums[i]);
    }
    for(int milk : possibleMilk){
        cout<<milk<<" has "<<milkNums[milk]<<endl;
    }
    fout<<maxNeeded;

}