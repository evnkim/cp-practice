#include<iostream>
#include<map>

using namespace std;

int main(){
    int n;
    cin>>n;
    int prefSum[n +  1];
    prefSum[0] = 0;
    for(int i = 1; i < n+1; i++){
        int num;
        cin>>num;
        prefSum[i] =(prefSum[i-1] + (num % n + n)) % n;
    }
    map<int,long long> modulos;
    for(int i = 0; i < n+1; i++){
        modulos[prefSum[i]]++;
    }
    long long count = 0;
    for(pair<int,long long> p : modulos){
        count += p.second * (p.second - 1) / 2;
    }
    cout<<count;
}