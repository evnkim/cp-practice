/*
ID: evan.e.1
TASK: test
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    int N;
    cin >> N;
    
    int count = 0;
    int diff = N;
    int num  =N;
    while(diff > 1){
        diff = diff / 3 + diff / 5 - diff / 15;
        num += diff;
    }


    while(count < N){
        num++;
        count = num - (num / 3 + num / 5 - num / 15);
    }
    cout<<num;


    return 0;
}