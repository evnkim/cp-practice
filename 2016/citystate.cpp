#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    set<pair<string,string>> s;
    for(int i = 0; i < N; i++){
        string city,state;
        cin>>city,state;
        s.insert({city,state});
        s.insert({state,city});
    }
    for(auto it = s.begin(); it != s.end(); ++it){
        auto current = it;
        for()
    }

}