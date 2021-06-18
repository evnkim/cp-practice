#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    long long pows10mod[200002];
    long long numMod[200002];
    vector<int> nums;
    string bruh;
    cin>>bruh;
    
    for(unsigned int i = 0; i < bruh.length(); i++){
        nums.insert(nums.begin(),(int) (bruh[i] - '0'));  
    }
    
    numMod[0] = nums[0] % 2019;
    pows10mod[0] = 1;
    int eachModCount[2019];
    
    for(int i = 0; i < 2019; i++){
        eachModCount[i] = 0;
    }
    
    for(unsigned int i = 1; i < nums.size(); i++){
        pows10mod[i] = (pows10mod[i-1] * 10 )% 2019;
        numMod[i] = (numMod[i-1] + (pows10mod[i] * nums[i] % 2019)) % 2019;
        eachModCount[numMod[i]]++;
    }
    
    int totPairs =  0;
    eachModCount[0]++;
    
    for(unsigned int i = 0; i < 2019; i++){
        if(eachModCount[i] >= 2){
            totPairs += eachModCount[i] * (eachModCount[i] - 1) / 2;
        }
    }
    cout<<totPairs;
    return 0;
}