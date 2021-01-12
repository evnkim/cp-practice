/*
ID: Dodgers66
TASK: mixmilk
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    ofstream fout ("mixmilk.out");
    ifstream fin ("mixmilk.in");

    int c1,m1,c2,m2,c3,m3;

    fin>>c1>>m1>>c2>>m2>>c3>>m3;

    for(int i = 0; i < 100; i++){
        if(i % 3 == 0){
            if(m1 > c2 - m2){
                m1 -= c2 - m2;
                m2 = c2;
            }
            else{
                m2 += m1;
                m1 = 0;
            }
        }
        else if(i % 3 == 1){
            if(m2 > c3 - m3){
                m2 -= c3 - m3;
                m3 = c3;
            }
            else{
                m3 += m2;
                m2 = 0;
            }

        }
        else
        {
            if(m3 > c1 - m1){
                m3 -= c1 - m1;
                m1 = c1;
            }
            else{
                m1 += m3;
                m3 = 0;
            }
        }
        
    }
    fout<<m1<<"\n"<<m2<<"\n"<<m3;
    return 0;

}
