#include<iostream>
#include<algorithm>

using namespace std;


int main(){
    int N, K;
    cin>>N>>K;
    int startStop[N+2];
    
    for(int i = 0;i < N+2; i++)
        startStop[i] = 0;

    
    for(int i = 0; i< K; i++){
        int start, end;
        cin>>start>>end;
        end++;
        startStop[start]++;
        startStop[end]--;
    }
    int height[N+2];
    height[0] = 0;
    for(int i = 1; i <= N; i++){
        height[i] =  height[i-1] + startStop[i];
    }
    sort(height + 1, height + N+1);
    cout<<height[(1+N)/2];
}