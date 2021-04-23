#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;

    long long minsum;
    long long prefsum[n+1];
    minsum = 0;
    prefsum[0] = 0;
    long long maxSum;

    for(int i = 1; i <= n; i++){
        long long next;
        cin>>next;
        if(i == 1)
            maxSum = next;
        prefsum[i] = prefsum[i-1] + next;
        minsum = min(minsum,prefsum[i-1]);
        maxSum = max(maxSum, prefsum[i] - minsum);
    }
    cout<<maxSum;

}