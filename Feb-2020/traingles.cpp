#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){

    ofstream fout ("triangles.out");
    ifstream fin ("triangles.in");

    
    int N;
    fin>>N;
    int xCoords[N];
    int yCoords[N];
    for(int i = 0; i < N;i++){
        fin>>xCoords[i]>>yCoords[i];
    }
    int maxArea = 0;
    for(int i = 0; i < N ;i++){
        int x = xCoords[i];
        int y = yCoords[i];
        for(int j = 0; j < N; j++){
            if(xCoords[j] != x || j == i)
                continue;
            for(int k = 0; k < N; k++){
                if(yCoords[k] != y || k == j || k == i)
                    continue;
                maxArea = max(abs((xCoords[k] - x) * (yCoords[j] - y)),maxArea);
            }
        }
    }
    fout<<maxArea;


}