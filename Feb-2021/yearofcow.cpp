#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int N,K;
    cin>>N>>K;

    int waits = N - 1 - K + 2;

    vector<int> ancestors;
    vector<pair<int,int>> differences;

    bool waiting[N-1];

    for(int i = 0; i < N; i++){
        int year;
        cin>>year;
        year = 1200000000 - year;
        ancestors.push_back(year);
    }
    sort(ancestors.begin(),ancestors.end());
    for(int i = 0; i < ancestors.size() - 1; i++){
        int later = ancestors[i + 1];
        int earlier = ancestors[i];
        int diff = ((later / 12) - (earlier / 12)) * 12;
        differences.push_back({diff,i});
    }



    sort(differences.begin(),differences.end());
    for(int i = 0 ; i < N-1; i++){
        if(i < waits){
            waiting[differences[i].second] = true;
        }
        else{
            waiting[differences[i].second] = false;
        }
        //cout<<"Betweeen "<<ancestors[differences[i].second + 1]<<" and "<<ancestors[differences[i].second]<<" there is difference "<<differences[i].first<<endl;
    }

    bool currWaiting = false;

    int totYears = 0;

    for(int i = 0; i < N ; i++){
        int add = 0;
        if(i != 0 && waiting[i-1]){
            int later = ancestors[i];
            int earlier = ancestors[i-1];
            int diff = ((later / 12) - (earlier / 12)) * 12;
            add = diff;
        }
        else{
            add = 12;
        }
        totYears += add;
        //cout<<"at stage "<<i<<" added "<<add<<endl;
    }
    cout<<totYears;


}