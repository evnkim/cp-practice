#include <iostream>
#include <map>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    map<int,int> m;
    for(int i = 1; i <= n; i++){
        int val;
        cin>>val;
        m[i] = val;
    }
    for(int i =1; i < n; i++){
        for(int j = i +1; j <= n; j++){
            if(m[i] + m[j] == x){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}