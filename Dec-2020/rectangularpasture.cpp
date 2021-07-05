#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

long long prefSum[50][50];

bool ycomp(vector<int> p, vector<int> q) { return p[1] < q[1]; }

int main(){
    int N;
    cin >> N;
    vector<vector<int>> coords;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        vector<int> bruh{x, y, i};
        coords.push_back(bruh);
    }

    //compressing coords
    sort(coords.begin(), coords.end());
    for (int i = 0; i < N; i++)
    {
        coords[i][0] = i + 1;
    }
    sort(coords.begin(), coords.end(), ycomp);
    for (int i = 0; i < N; i++)
    {
        coords[i][1] = i + 1;
    }

    // for(int i = 0; i < coords.size(); i++){
    //     cout<<coords[i][0]<<","<<coords[i][1]<<": "<<coords[i][2]<<endl;
    // }

    // int coordsMap[51][51];

    // for(int i = 0; i < 51; i++){
    //     for(int j = 0; j < 51; j++){
    //         coordsMap[i][j] = -1;
    //     }
    // }

    // for(int i = 0; i < N; i++){
    //     coordsMap[coords[i][0]][coords[i][1]] = coords[i][2];
    // }



    // set<int> prefSum[51][51];
    // for(int x = 0; x < 51; x++){
    //     set<int> emptySet;
    //     prefSum[x][0] = emptySet;
    //     prefSum[0][x] = emptySet;
    // }

    // for(int x = 1; x < 51; x++){
    //     for(int y = 1; y < 51; y++){
    //         set<int> setToFill;
    //         set<int> minusX = prefSum[x-1][y];
    //         set<int> minusY = prefSum[x][y-1];
    //         for(auto it = minusX.begin(); it != minusX.end(); ++it){
    //             setToFill.insert(*it);
    //         }
    //         for(auto it = minusY.begin(); it != minusY.end(); ++it){
    //             setToFill.insert(*it);
    //         }
    //         if(coordsMap[x][y] != -1){
    //             setToFill.insert(coordsMap[x][y]);
    //         }
    //         prefSum[x][y] = setToFill;
    //     }
    // }

    // set<set<int>> subsets;

    // for(int smallX = 1; smallX < 51; smallX++){
    //     for(int smallY = 1; smallY < 51; smallY++){
    //         for(int bigX = smallX; bigX < 51; bigX++){
    //             for(int bigY = smallY; bigY < 51; bigY++){
    //                 set<int> setToFill = prefSum[bigX][bigY];
    //                 set<int> minusX = prefSum[smallX-1][bigY];
    //                 set<int> minusY = prefSum[bigX][smallY-1];
    //                 for(auto it = minusX.begin(); it != minusX.end(); ++it){
    //                     setToFill.erase(*it);
    //                 }
    //                 for(auto it = minusY.begin(); it != minusY.end(); ++it){
    //                     setToFill.erase(*it);
    //                 }
    //                 subsets.insert(setToFill);
    //             }
    //         }
    //     }
    // }

    // // for(int x = 1; x < 5; x++){
    // //     for(int y = 1; y < 5; y++){
    // //         cout<<x<<" "<<y<<": ";
    // //         for(auto it = prefSum[x][y].begin(); it != prefSum[x][y].end();++it){
    // //             cout<<*it<<",";
    // //         }
    // //         cout<<endl;
    // //     }
    // // }

    // // for(set<set<int>>::iterator it = subsets.begin(); it!=subsets.end(); ++it){
    // //     for(set<int>::iterator i = it->begin(); i!=it->end(); ++i){
    // //         cout<<*i<<",";
    // //     }
    // //     cout<<endl;
    // // }
    // cout<<subsets.size();

        

    
}