/*
ID: Dodgers66
TASK: test
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("blist.out");
    ifstream fin ("blist.in");
    int N;
    fin>>N;
    int b[N],s[N],t[N];
    int maxT = 0;
    for(int i =0; i < N; i++){
        fin>>s[i]>>t[i]>>b[i];
        if(t[i] > maxT)
            maxT = t[i];
   }
   int maxBuck = 0;
   for(int i =0; i < maxT; i++){
       int bucketsForTime = 0;
       for(int j = 0; j < N; j++){
           if(s[j] <= i && t[j] >= i){
               bucketsForTime += b[j];
           }
       }
       if(maxBuck < bucketsForTime){
           maxBuck = bucketsForTime;
       }
   }
   fout<<maxBuck;

    return 0;
}