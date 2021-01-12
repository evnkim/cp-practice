#include <iostream>
#include <vector>

int main(){
    int N;
    cin>>N;
    char dir[N];
    int x[N];
    int y[N];
    for(int i = 0; i < N; i++){
        cin>>dir[i]>>x[i]>>y[i];
    }
    int collisions[N][N];
    
    int mins[N][2];

    for(int i =0; i < N; i++){
        int minCow = -1;
        int minDist = -1;
        for(int j = 0; j < N; j++){
            if(i == j || dir[i] == dir[j] )
                continue;
            if(dir[i] == 'E'){
                if(x[j] < x[i] || y[j] > y[i])
                    continue;
                if(x[j] - x[i] >= y[i] - y[j])
                    continue;
                int tempMin = -1;
                for(int k = 0; k < N; k++){
                    if(k == i || k == j || dir[k] == dir[j])
                        continue;
                    if(x[k] > x[j] || y[j] > y[k])
                        continue;
                    if(x[j] - x[k] >= y[k] - y[j])
                        continue;
                    if(y[k] - y[j] < tempMin || tempMin == -1)
                        tempMin = y[k] - y[j];
                }
                if(tempMin < y[i] - y[k])
                    continue;
                if(y[i] - y[k] < minDist || minDist == -1){
                    minDist = y[i] - y[k];
                }
                
            }
        }
    }

}