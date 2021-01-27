#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N,Q;

int stepUps(string s){
    if(s.length() <= 0)
        return 0;
    vector<int> upDown;
    char prev = s[0];
    upDown.push_back((int) (s[0] - 'A'));
    for(int i = 1; i < (int) s.length(); i++){
        upDown.push_back((int) (s[i] - 'A'));
        // if(s[i] != prev){
        //     upDown.push_back((int) (s[i] - 'A'));
        //     // if( < upDown[minIndex])
        //     //     minIndex = upDown.size() -1;
        // }
        // prev = s[i];
    }
    int count = 0;
    bool paint = false;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < (int) upDown.size(); j++){
            if(!paint && upDown[j] == i){
                paint = true;
                count++;
            }
            if(j == (int) upDown.size() - 1 || upDown[j] < i)
                paint = false;
        }
    }
    return count;

}

int main(){
    cin>>N>>Q;
    string sequence;
    cin>>sequence;
    for(int i = 0; i < Q; i++){
        int lower,upper;
        cin>>lower>>upper;

        cout<<stepUps(sequence.substr(0,lower - 1)) + stepUps(sequence.substr(upper,N - upper))<<endl;
    }

    return 0;
}