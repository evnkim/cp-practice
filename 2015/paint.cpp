#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ofstream fout ("paint.out");
    ifstream fin ("paint.in");
    
    int a,b,c,d;
    
    fin>>a>>b>>c>>d;
    if((a <= d && a >= c)|| (b >= c && b <= d)  || (c >= a && c <= b) || (d >= a && d <= b))
        fout<<max(b,d) - min(a,c);
    else
    {
        fout<<(b-a)+(d-c);
    }
    
}