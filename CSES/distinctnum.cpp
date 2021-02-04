#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> s;
    int n;
    cin>>n;
    while(n--){
        int bruh;
        cin>>bruh;
        s.insert(bruh);
    }
    cout<<s.size();


    return 0;
}