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
    int count = 0;
    for(int x1 = 0; x1 < N; x1++){
        for(int x2 = x1; x2 < N; x2++){
            for(int y1 = 0; y1 <N; y1++){
                for(int y2 = y1; y2 < N; y2++){
                    
                    int minimum = 200;

                    for(int i = x1; i < x2 + 1; i++){
                        for(int j = y1; j < y2 + 1; j++){
                            minimum = min(minimum, vals[i][j]);
                        }
                    }

                    if(minimum == 100){
                        count++;
                    }

                }
            }
        }
    }
    cout<<count;
}