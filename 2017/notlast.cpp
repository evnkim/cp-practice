#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ofstream fout ("notlast.out");
    ifstream fin ("notlast.in");
    int N;
    fin>>N;
    map<string, int> cows;
    cows["Bessie"] = 0;
    cows["Elsie"] = 0;
    cows["Daisy"] = 0;
    cows["Gertie"] = 0;
    cows["Annabelle"] = 0;
    cows["Maggie"] = 0;
    cows["Henrietta"] = 0;
    
    while(N--){
        string name;
        int milk;
        fin>>name>>milk;
        cows[name] = cows[name] + milk;
    }
    vector<pair<int, string>> sortCows;
    int mini = cows.begin()->second;
    for(pair<string,int> x : cows){
        cout<<x.first<<" "<<x.second<<endl;
        mini = min(mini,x.second);
        sortCows.push_back({x.second, x.first});
    }
    int secondToLast = 0;
    sort(sortCows.begin(),sortCows.end());
    for(int i = 0; i < sortCows.size(); i++){
        if(sortCows[i].first > mini){
            if(i < sortCows.size() - 1 && sortCows[i+1].first == sortCows[i].first){
                fout<<"Tie"<<'\n';
                return 0;
            }
            fout<<sortCows[i].second<<'\n';
            return 0;
        }
    }
    fout<<"Tie"<<'\n';
    

}