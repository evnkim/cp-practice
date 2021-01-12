#include <iostream>

using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int sum = 0;

        for(int i =0;i < n; i++){
             cin>>arr[i];
            sum += arr[i];
        }
        int num = n + 1;
        while(num--){
            if(sum % num != 0){
                continue;
                
            }
            int commn = sum / num;
            int ind = 0;
            while(ind >= 0 && ind < *(&arr + 1) - arr){

                int sum = 0;
                while(sum < commn){
                    if(ind >= *(&arr + 1) - arr)
                        break;
                    sum += arr[ind];
                    ind++;
                }
                if(sum != commn)
                    ind = -1;
                    break;
            }
            if(ind != -1){
                cout<<n - num<<endl;
                break;
            }

        }
        

    }
    return 0;
}

