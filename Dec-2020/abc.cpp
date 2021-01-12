#include <iostream>

using namespace std;

int main(){
    int nums[7];
    for(int  i =0; i < 7 ;i++){
        cin>>nums[i];
    }
    for(int i =0; i < 6; i++){
        for(int j = 0; j < 6;j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<" "<<nums[3]<<" "<<nums[4]<<" "<<nums[5]<<" "<<nums[6]<<" ";
    if(nums[0] + nums[1] + nums[2] == nums[6]){
        cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2];   
    }
    else{
        cout<<nums[0]<<" "<<nums[1]<<" "<<nums[3];
    }
    return 0;
}