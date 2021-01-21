#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> weights(2 * n);
    for(int i = 0; i < 2 * n; i++)
        cin>>weights[i];
    sort(weights.begin(),weights.end());
    int minSum = -1;
    for(int i =0; i < 2 * n -1; i++){
        for(int j = i+1; j < 2 * n; j++){
            int sum = 0;
            for(int k = 0; k < 2 * n - 1; k++){
                if(k == i || k == j)
                    continue;
                else if(k+1 == i || k+1 == j){
                    sum += abs(weights[k+2] - weights[k]);
                    k += 2;
                    continue;
                }
                sum += abs(weights[k+1] - weights[k]);
                k += 1;

            }
            if(minSum == -1)
                minSum = sum;
            if(sum < minSum){
                minSum = sum;
            }
        }
    }
    cout<<minSum;

    
}