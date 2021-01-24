/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: evan.e.1
TASK: gymnastics
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

using namespace std;

// int getIndex(vector<int> v, int K)
// {
//     std::vector<int>::iterator it;

//     it = find (v.begin(), v.end(), K);
//     if (it != v.end()){
//         return it-v.begin();
//     }
//     else{
//         return -1;
//     }
// }

// int main() {
//     ofstream fout ("gymnastics.out");
//     ifstream fin ("gymnastics.in");
//     int k,n;
//     fin >> k >> n;

//     vector<int> rank(n);



//     for(int i = 0; i < n; i++){
//         fin >> rank[i];
//     }


//     vector<vector<int>> pairs(n * (n-1)/2, vector<int>(2,0));

//     int count = 0;
//     for(int i = 0; i < n-1; i++){
//         for(int j = i+1; j < n; j++){
//             pairs[count] = {rank[i],rank[j]};
//             count++;
//         }
//     }
//     for(int i = 1; i < n - 1; i++){
//         for(int i = 0; i < n; i++){
//             fin >> rank[i];
//         }
//         for(unsigned i = 0; i < pairs.size(); i++){
//             int firstIndex = getIndex(rank,pairs[i][0]);
//             int secondIndex = getIndex(rank,pairs[i][1]);
//             if(firstIndex > secondIndex){
//                 pairs.erase(pairs.begin() + i);
//                 i -= 1;
//             }
//         }
//         cout<<"debug";
//     }
//     fout<<pairs.size();

//     return 0;
// }

//REODOING ON 1/23/2021
int K,N;


int getPos(int num, int * rankingsbruh){
    for(int i = 0; i < N; i++){
        if(*(rankingsbruh+i) == num){
            return i;
        }
    }
    return 0;
}

int main(){
    ofstream fout ("gymnastics.out");
    ifstream fin ("gymnastics.in");
    fin>>K>>N;
    
    int rankings[K][N];

    

    for(int i =0; i < K; i++){
        for(int j = 0; j < N; j++){
            fin>>rankings[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = i+ 1; j < N; j++){
            int firstPlace = rankings[0][i];
            int secondPlace = rankings[0][j];
            bool bruh = true;
            for(int k = 1; k < K; k++){
                int firstPos = getPos(firstPlace,rankings[k]);
                int secondPos = getPos(secondPlace,rankings[k]);
                if(firstPos > secondPos){
                    bruh = false;
                    break;
                }
            }
            if(bruh)
                count++;
        }
    }
    fout<<count;


}
