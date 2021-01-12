#include <iostream>
#include <math.h>

using namespace std;

int N;

bool stillMissing(int arr[]){
    for(int i = 1; i < N; i++){
        if(arr[i] == 0)
            return true;
    }
    return false;
}

int main(){
    
    cin>>N;
    int roads[N-1][2];
    int dist[N];
    dist[0] = 0;
    for(int i =0; i < N; i++){
        dist[i] = 0;
    }
    //cout<<"fjlskadjflksdajfklsajfksajdf"<<dist[1]<<endl;
    int oneConnect = 0;
    for(int i =0; i < N - 1; i++){
        cin>>roads[i][0]>>roads[i][1];
    }
    int doublingDays =(int) (log(N)/log(2.0));
    if(pow(2.0, doublingDays) != N){
        doublingDays++;
    }
    //cout<<"ok bruhmmer"<<dist[1]<<endl;
    for(int i = 0; i < N-1; i++){
        if(roads[i][0] == 1){
            dist[roads[i][1] -1] = 1;
            oneConnect++;
        }
        else if(roads[i][1] == 1){
            dist[roads[i][0] - 1] = 1;
            oneConnect++;
        }
    }
    //cout<<"ok bruh"<<dist[1]<<endl;
    int count = 1;
    while(stillMissing(dist)){
        //cout<<"bruh";
        for(int i =0; i < N-1; i++){
            if(dist[roads[i][0]-1] == count && dist[roads[i][1]-1] == 0){
                dist[roads[i][1]-1] = dist[roads[i][0]-1] + 1;
                //cout<<"bruh";
            }
            if(dist[roads[i][1]-1] == count && dist[roads[i][0]-1] == 0){
                dist[roads[i][0]-1] = dist[roads[i][1]-1] + 1;
            }
        }
        count++;
    }
    int maxi = 0;

    // for(int i =0; i < N; i++){
    //     for(int j = 0; j < N - 1; j++){
    //         if(max(j + dist[j],j+1 + dist[j+1]) > max(j+dist[j+1],j+1+dist[j]) ){
    //             int temp = dist[j];
    //             dist[j] = dist[j+1];
    //             dist[j+1] = dist[j];
    //         }
    //     }
    // }
    
    for(int i =0; i < N; i++){
        maxi = max(maxi,dist[i] + i -1);
    }
    cout<<"MAXI "<<maxi<<endl;
    if(oneConnect > maxi){
        cout<<doublingDays + oneConnect;
    }
    else{
        cout<<doublingDays + maxi;
    }

}