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

using namespace std;

bool containedElsewhere(string s, int i, int len){
    string seq = s.substr(i,len);
    if(s.find(seq) != string::npos){
        if(s.find(seq) >= i){
            if(s.erase(0,i+2).find(seq) != string::npos)
                return true;
        }

        return true;
    }
    return false;
}

bool testWork(string s, int len){
    for(int i =0; i <= s.length() - len; i++){
        if(containedElsewhere(s,i,len))
            return true;
    }
    return false;
}



int main() {
    ofstream fout ("whereami.out");
    ifstream fin ("3.in");
    int N;
    string sequence;
    fin >> N >> sequence;
    
    int minLen = 1;
    while(testWork(sequence,minLen)){
        minLen++;
        cout<<minLen;
    }
    fout<<minLen;

    return 0;
}

