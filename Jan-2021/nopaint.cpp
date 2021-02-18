#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int N,Q;

int countFunc(string sequence){
    int count;
    char currentMin = sequence[0];
    if(sequence.length() == 0)
        return 0;
    count = 1;
    for(int i = 1; i < sequence.length(); i++){
        if(sequence[i] > sequence[i-1]){
            count = count + 1;
        }
        else if(sequence[i] < currentMin){
            currentMin = sequence[i];
            count = count+1;
        }
    }
    return count;
}

int main(){
    
    //cin>>N>>Q;
    //ofstream fout ("nopaint.out");
    
    //string sequence;
    //cin>>sequence;
    cout<<countFunc("TDVTKTFDVTDTFCTDFKKKVTCTVCTFFTVTVFKCFTVKTKCTDVTCTFVKKKDC")<<endl;
    cout<<countFunc("TDTKCDVTVVFTDCCTVKTF");

    
    // for(int i  = 0; i < Q; i++){
    //     int a,b;
    //     cin>>a>>b;
    //     int tot;
    //     if(a != 1)
    //         tot = countFunc(sequence.substr(0,a-1)) + countFunc(sequence.substr(b,sequence.length() - b));
    //     else
    //     {
    //         tot = countFunc(sequence.substr(b,sequence.length() - b));
    //     }
        
    //     fout<<tot<<endl;            
    // }
    // return 0;


}