#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int prefArr[50001];
int N;

int firstOccur(int val){
    for(int i = 0; i < N + 1; i++){
        if(prefArr[i] == val){
            return i;
        }
    }
    return -1;
}
int lastOccur(int val){
    for(int i = N; i >= 0; i--){
        if(prefArr[i] == val){
            return i;
        }
    }
    return -1;
}

int maxDist(int residue){
    int first = firstOccur(residue);
    int second = lastOccur(residue);
    cout<<"For residue "<<residue<<" max was "<<first<<", "<<second<<endl;
    if(first == -1 || second == -1 || first == second)
        return -1;
    else
    {
        return second - first;
    }
    
}

int main(){
    ofstream fout ("div7.out");
    ifstream fin ("div7.in");

    
    fin>>N;

    prefArr[0] = 0;
    for(int i = 1; i < N+1; i++){
        fin>>prefArr[i];
        prefArr[i] = prefArr[i] % 7;
        prefArr[i] = ( prefArr[i] + prefArr[i-1] ) % 7;
    }
    int maxSize = 0;
    for(int i = 0; i < 7; i++){
        maxSize = max(maxSize, maxDist(i));
    }
    
    fout<<maxSize;

}