#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout ("billboard.out");
    ifstream fin ("billboard.in");
    //cow
    int x1,y1,x2,y2;

    //lawn
    int a1,b1,a2,b2;

    int ans;

    fin>>a1>>b1>>a2>>b2>>x1>>y1>>x2>>y2;

    if(y1 >= b1 && y1 <= b2 && x1 <= a1 && x2 >= a2){
        if(y2 >= b1 && y2 <= b2 && x1 <= a1 && x2 >= a2){
            ans = (b2 - b1)*(a2 - a1);
        }
        else
            ans = (y1 - b1) * (a2 - a1);
    }
    else if(y2 >= b1 && y2 <= b2 && x1 <= a1 && x2 >= a2){
        ans = (b2 - y2) * (a2 - a1);
    }
    else if(y1 <= b1 && y2 >= b2 && x1 >= a1 && x1 <= a2){
        if(y1 <= b1 && y2 >= b2 && x2 >= a1 && x2 <= a2){
            ans = (b2 - b1)*(a2 - a1);
        }
        else
            ans = (x1 - a1) * (b2 - b1);
    }
    else if(y1 <= b1 && y2 >= b2 && x2 >= a1 && x2 <= a2){
        ans = (a2 - x2) * (b2 - b1);
    }
    else{
        ans = (b2 - b1)*(a2 - a1);
    }


    fout<<ans;
}