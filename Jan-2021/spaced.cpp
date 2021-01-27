#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;

    int weights[N][N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>weights[i][j];
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i += 2){
        for(int j = 0; j < N; j+= 2){
            int arr[4] = {weights[i][j],weights[i+1][j],weights[i][j+1],weights[i+1][j+1]};
            sort(arr, arr+4);
            sum += arr[3] + arr[2];
        }
    }
    cout<<sum;
}