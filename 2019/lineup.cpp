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
#include <map>
#include <algorithm>

using namespace std;

vector<int> cowsNum {0,1,2,3,4,5,6,7};
vector<int> adj[8];

bool test(){
    for(int i = 0; i < 8; i++){
        if(adj[cowsNum[i]].size() == 0)
            continue;
        if(adj[cowsNum[i]].size() == 1){
            if(*(cowsNum.begin() + i  +1)== adj[cowsNum[i]][0] || *(cowsNum.begin() + i - 1) == adj[cowsNum[i]][0])
                continue;
            else
                return false;
        }
        if(adj[cowsNum[i]].size() == 2){
            if((*(cowsNum.begin() + i  +1)== adj[cowsNum[i]][0] || *(cowsNum.begin() + i - 1) == adj[cowsNum[i]][0]) && (*(cowsNum.begin() + i  +1)== adj[cowsNum[i]][1] || *(cowsNum.begin() + i - 1) == adj[cowsNum[i]][1]))
                continue;
            else
                return false;
        }
    }
    return true;
}

int main() {
    ofstream fout ("lineup.out");
    ifstream fin ("lineup.in");
    int N;
    
    string dummy;

    map<string,int> cowsToInt{
        {"Beatrice",0},
        {"Belinda",1},
        { "Bella",2},
        {"Bessie",3},
        {"Betsy",4},
        {"Blue",5},
        {"Buttercup",6},
        {"Sue",7}
    };
    map<int,string> intToCows{
        {0,"Beatrice"},
        {1,"Belinda"},
        {2,"Bella"},
        {3,"Bessie"},
        {4,"Betsy"},
        {5,"Blue"},
        {6,"Buttercup"},
        {7,"Sue"}
    };
    

    fin>>N;

    for(int i = 0; i < N; i++){
        string first, second;
        fin>>first>>dummy>>dummy>>dummy>>dummy>>second;
        int one, two;
        one = cowsToInt[first];
        two = cowsToInt[second];
        adj[one].push_back(two);
        adj[two].push_back(one);
    }

    while(next_permutation(cowsNum.begin(),cowsNum.end())){
        if(test())
            break;
    }
    for(int i = 0; i < 8; i++){
        fout<<intToCows[cowsNum[i]]<<endl;
    }
    return 0;
}