#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> times;
    for(int i = 0; i < n; i++){
        int a,b;
        cin>>a>>b;
        times.push_back({a,1});
        times.push_back({b,-1});
    }
    sort(times.begin(),times.end());
    int currNum = 0;
    int maxNum = 0;
    for(int i = 0; i < times.size(); i++){
        currNum += times[i].second;
        maxNum = max(maxNum,currNum);
    }
    cout<<maxNum;
}