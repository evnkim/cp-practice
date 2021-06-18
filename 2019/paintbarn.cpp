#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

// vector<pair<int,int>> startingPairs;
// vector<pair<int,int>> endingPairs;


int main(){
    
    //ofstream fout ("paintbarn.out");
    //ifstream fin ("paintbarn.in");
    cout<<"asoifjsadkfjaslkfaslfjasdf";
    int N,K;
    cin>>N>>K;
    cout<<N<<K;
    int minX=0,minY=0, maxX=0, maxY=0;

    cout<<"hello!";

    int netExtra[1002][1002];
    for(int i =0; i < 1002; i++){
        for(int j= 0; j < 1002; j++)
            netExtra[i][j] = 0;
    }

    for(int i = 0 ; i < N; i++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1++;
        x2++;
        y1++;
        y2++;
        
        if(i == 0){
            minX = x1;
            minY = y1;
            maxX = x2;
            maxY = y2;
        }
        else{
            minX = min(x1,minX);
            minY = min(y1,minY);
            maxX = max(x2,maxX);
            maxY = max(y2,maxY);
        }

        netExtra[x1][y1]++;
        netExtra[x2][y2]--;
        
        
        //startingPairs.push_back({x1,y1});
        //endingPairs.push_back({x2,y2});

        cout<<"hello!";
    }
    // //sort(startingPairs.begin(),startingPairs.end());
    // //sort(endingPairs.begin(),endingPairs.end());

    cout<<"sorted!";
    cout<<maxX<<"  "<<maxY<<endl;

    int area[1002][1002];

    for(int i = minX-1; i <= maxX; i++)
        area[i][minY-1] = 0;
    for(int i = minY-1; i <= maxY; i++)
        area[minX-1][i] = 0;

    cout<<"things initialized!";

    int count = 0;

    for(int x = minX; x <= maxX; x++){
        for(int y = minY; y <= maxY; y++){
            cout<<"looping...("<<x<<","<<y<<")...";
            // int extra = 0;
            // pair<int,int> coords1(x,y);
            // pair<int,int> coords2(x-1,y-1);
            // if(find(startingPairs.begin(),startingPairs.end(),coords1) != startingPairs.end())
            //     extra++;
            // if(find(endingPairs.begin(),endingPairs.end(),coords1) != endingPairs.end())
            //     extra--;
            //area[x][y] = area[x-1][y] + area[x][y-1] - area[x-1][y-1] + netExtra[x][y];
            //if(area[x-1][y] + area[x][y-1] - area[x-1][y-1] + netExtra[x][y] == 5)
                //count++; 
        }
    }

    cout<<count;
    
    return 0;
}