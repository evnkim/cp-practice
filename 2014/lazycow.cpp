#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

int dp[402][402];

int main(){
    int N, K;
    ofstream fout ("lazy.out");
    ifstream fin ("lazy.in");
    fin>>N>>K;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N;j++){
            fin>>dp[i][j];
        }
    }
    for(int i = 1; i<= N; i++){
        //cout<<"hello";
        for(int j= 1; j<= N; j++){
            dp[i][j] += dp[i-1][j];
        }
    }
    int maxx = 0;
    for(int i = 1; i<= N; i++){
        //cout<<"yaboi";
        for(int j = 1; j <= N; j++){
            int sum = 0;
            for(int k = max(j - K,1); k <= min(N,j+K);k++){
                //cout<<"bruh";
                //cout<<i<<","<<j<<" and k is "<<k<<" and we are adding on "<< dp[min(N,i+(K - abs(j-k)))][k] - dp[max(0,i-(K - abs(j-k)) -1)][k]<<endl;
                sum += dp[min(N,i+(K - abs(j-k)))][k] - dp[max(0,i-(K - abs(j-k)) -1)][k];
            }
            maxx = max(maxx,sum);
        }
    }
    fout<<maxx;
}