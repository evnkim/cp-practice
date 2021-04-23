#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;

    int vals[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>vals[i][j];
        }
    }

    int prefArr[N+1][N+1];
    for(int i = 1; i < N + 1; i++){
        prefArr[i][0] = 0;
        for(int j = 1; j <= N; j++){
            if(j == 1)
                prefArr[i][j] = vals[i][j-1] ^ prefArr[i][j-1];
            else
                prefArr[i][j] = min(prefArr[i][j-1],vals[i][j-1] ^ prefArr[i][j - 1]);
        }
    }

    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < N+1; j++){
            cout<<prefArr[i][j]<<" ";
        }
        cout<<endl;
    }

    int count = 0;

    for(int i = 1; i < N+1; i++){
        for(int j = i; j < N+1; j++){
            for(int k = 1; k < N+1; k++){
                for(int l = k; l < N+1; l++){
                    int minimum = 200;
                    for(int x = i; x <= j; x++){
                        minimum = min(minimum, (prefArr[x][l] ^ prefArr[x][k-1]));
                    }
                    cout<<minimum<<endl;
                    if(minimum == 100){
                        count++;
                    }
                }
            }
        }
    }
    cout<<count;

    // prefArr2[N+1][N+1];
    // for(int i = 0; i < N+1; i++)
    //     prefArr2[0][i] = 0;
    // for(int i = 1; i < N+1; i++){
    //     for(int j = 1; j < N+1; j++){
    //         prefArr2[i][j] = max(prefArr[])
    //     }
    //         prefArr2[i]

    // }



    
    // int a = 500;
    // int b = 323;
    // int c = 53;
    // int d = 672;
    // cout<<(a ^ b)<<endl;
    // cout<<(a ^ b ^ d)<<endl;
    // int thing = (((a ^ b) ^ c) ^ d);

    // cout<<((a ^ b ^ d) ^ (a ^ b));
    // cout<< (5 ^ 5);
}