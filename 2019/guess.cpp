#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

vector<string> traits[100];

int commonalities(vector<string> arr1, vector<string> arr2){
    int count = 0;
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr2.size(); j++){
            if(arr1[i] == arr2[j]){
                count++;
            }
        }
    }
    return count;
}

int main(){
    ofstream fout("guess.out");
    ifstream fin("guess.in");

    int N;
    fin>>N;
    for(int i = 0; i < N; i++){
        string trash;
        fin>>trash;
        int count;
        fin>>count;
        for(int j = 0; j < count; j++){
            string trait;
            fin>>trait;
            traits[i].push_back(trait);
        }
    }
    int maxCommon = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i+1; j < N; j++){
            maxCommon = max(maxCommon, commonalities(traits[i],traits[j]));
        }
    }
    fout<<maxCommon + 1;

}