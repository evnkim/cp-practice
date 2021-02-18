#include <iostream>

using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    long long prefix[N];
    for(int i = 0; i < N; i++){
        if(i == 0){
            cin>>prefix[i];
        }
        else{
            int num;
            cin>>num;
            prefix[i] = prefix[i-1] + num;
        }
    }
    for(int i = 0; i < Q; i++){
        int a,b;
        cin>>a>>b;
        if(b == 0)
            cout<<0;
        else if(a == 0)
            cout<<prefix[b-1];
        else
            cout<<prefix[b-1] - prefix[a-1];
        cout<<'\n';
    }
}