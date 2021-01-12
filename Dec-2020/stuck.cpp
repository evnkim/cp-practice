#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int x[N];
    int y[N];
    char dir[N];
    for(int i = 0; i < N; i++){
        cin>>dir[i];
        cin>>x[i];
        cin>>y[i];
    }
    // int mins[N][2];
    for(int i =0; i < N; i++){
        int min  = -1;
        for(int j = 0; j < N; j++){
            if(j == i)
                continue;
            if(dir[i] == dir[j]){
                continue;
            }
            
            if(dir[i] == 'E'){
                if(x[i] > x[j] || y[j] > y[i])
                    continue;
                if(x[j] - x[i] <= y[i] - y[j])
                    continue;
                // if(y[i] - y[j] > tempMin && tempMin != -1)
                //     continue;
                if(min == -1 || min > x[j] - x[i]){
                    //Check if they intersect before reaching this point
                    int tempMin = -1;
                    for(int k = 0; k < N; k++){
                        if(k == i || k == j)
                            continue;
                        if(dir[j] == 'E'){
                            if(x[j] > x[k] || y[k] > y[j])
                                continue;
                            if(x[k] - x[j] <= y[j] - y[k])
                                continue;
                            if(tempMin == -1 || tempMin > x[k] - x[j]){
                                tempMin = x[k] - x[j];
                            }
                        }
                        else{
                            if(y[j] > y[k] || x[k] > x[j]){
                                continue;
                            }
                            if(y[k] - y[j] <= x[j] - x[k]){
                                continue;
                            }
                            if(tempMin == -1 || tempMin > y[k] - y[j]){
                                tempMin = y[k] - y[j];
                            }
                        }
                    }
                    if(tempMin <= y[i] - y[j] && tempMin != -1)
                        continue;
                    min = x[j] - x[i];
                }
            }
            else{
                if(y[i] > y[j] || x[j] > x[i]){
                    continue;
                }
                if(y[j] - y[i] <= x[i] - x[j]){
                    continue;
                }
                // if(x[i] - x[j] > tempMin && tempMin != -1){
                //     continue;
                // }
                if(min == -1 || min > y[j] - y[i]){
                    int tempMin = -1;
                    for(int k = 0; k < N; k++){
                        if(k == i || k == j)
                            continue;
                        if(dir[j] == 'E'){
                            if(x[j] > x[k] || y[k] > y[j])
                                continue;
                            if(x[k] - x[j] <= y[j] - y[k])
                                continue;
                            if(tempMin == -1 || tempMin > x[k] - x[j]){
                                tempMin = x[k] - x[j];
                            }
                        }
                        else{
                            if(y[j] > y[k] || x[k] > x[j]){
                                continue;
                            }
                            if(y[k] - y[j] <= x[j] - x[k]){
                                continue;
                            }
                            if(tempMin == -1 || tempMin > y[k] - y[j]){
                                tempMin = y[k] - y[j];
                            }
                        }
                    }
                    if(tempMin <= x[i] - x[j] && tempMin != -1 )
                        continue;
                    min = y[j] - y[i];
                }
            }

        }
        // mins[i][0] = min[0];
        // mins[i][1] = min[1];
        if(min != -1){
            cout<<min<<endl;
        }
        else{
            cout<<"Infinity"<<endl;
        }
    }
    return 0;
}