#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minDiff;
long long weights[20];
int n;
long long totWeight;

void search(int k, long long weight){
    if(k == n){
        minDiff = min(minDiff, abs((totWeight - weight) - weight));
    }
    else{
        search(k+1,weight);
        search(k+1,weight + weights[k]);
    }
}

int main(){
    cin>>n;
    totWeight = 0;

    for(int i = 0; i < n; i++){
        cin>>weights[i];
        totWeight += weights[i];
    }
    minDiff = totWeight;

    search(0,0);
    cout<<minDiff;

}


/*Bitmask way of going through subsets is below!!*/

// for (int j = 0; j < n; j++) {
// 			if (mask & (1 << j)) { //if the j-th bit is toggled
// 				s1 += weights[j];
// 			}
// 			else{
// 				s2 += weights[j];
// 			}
// 		}