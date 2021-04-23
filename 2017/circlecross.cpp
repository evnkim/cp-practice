#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string input;
    

    ofstream fout ("circlecross.out");
    ifstream fin ("circlecross.in");
    
    fin>>input;

    string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count = 0;
    for(int i = 0; i < 25; i++){
        for(int j = i + 1; j < 26; j++){
            char letter1 = letters[i];
            char letter2 = letters[j];

            int loc1a = -1,loc1b = -1,loc2a = -1,loc2b = -1;

            for(int x = 0; x < 52; x++){
                if(input[x] == letter1){
                    if(loc1a == -1)
                        loc1a = x;
                    else
                        loc1b = x;
                }
                if(input[x] == letter2){
                    if(loc2a == -1)
                        loc2a = x;
                    else
                        loc2b = x;
                }
            }
            if(loc1a < loc2a){
                if(loc1b > loc2a && loc1b < loc2b)
                    count++;
            }   
            if(loc1a > loc2a){
                if(loc2b > loc1a && loc1b > loc2b)
                    count++;
            }

        }
    }
    fout<<count;
}