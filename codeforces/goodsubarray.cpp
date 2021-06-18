#include<iostream>
#include<map>

using namespace std;

int main(){
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        int prefSum[n+1];
        prefSum[0] = 0;
        for(int i = 1; i < n+1; i++){
            char num;
            cin>>num;
            int bruh = num - '0';
            prefSum[i] = prefSum[i-1] + bruh;
        }
        map<int,long long> diffCount;
        for(int i = 0; i < n+1; i++){
            diffCount[prefSum[i] - i]++;
        }   
        
        long long count = 0;
        
        for(auto thing : diffCount){
            count += thing.second * (thing.second - 1) / 2;
        }
        cout<<count<<endl;
    }
    
        
}