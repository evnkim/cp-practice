#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int petals[N];
    for(int i =0; i < N; i++){
        cin>>petals[i];
    }
    int totalCount = 0;
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            int sum = 0;
            for(int l = i; l <= j; l++){
                sum += petals[l];
            }
            if(sum % (j - i + 1) != 0){
                continue;
            }
            else{   
                sum = sum / (j - i + 1);
                for(int k = i; k <= j; k++){
                    if(petals[k] == sum){
                        totalCount++;
                        break;
                    }
                }
            }
        }
    }
    totalCount += N;
    cout<<totalCount;
}