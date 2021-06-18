#include <iostream>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;

    int numTree[n+1][n+1];
    for(int i = 0; i < n+1;i++){
        numTree[i][0] = 0;
        numTree[0][i] = 0;
    }


    for (int i = 1; i < n+1; i++){
        for (int j = 1; j  < n+1; j++)
        {
            char next;
            cin>>next;
            if(next =='*')
                numTree[i][j] = numTree[i-1][j] + numTree[i][j-1] - numTree[i-1][j-1] + 1;
            else
                numTree[i][j] = numTree[i-1][j] + numTree[i][j-1] - numTree[i-1][j-1];

        }
        
    }
    while(q--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<numTree[x2][y2] - numTree[x2][y1 - 1] - numTree[x1-1][y2] + numTree[x1-1][y1-1]<<endl;
    }    
}