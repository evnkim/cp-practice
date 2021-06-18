#include <iostream>

using namespace std;

void insertsort(int* start, int* end){
    if(start == end){
        return;
    }
    end--;
    insertsort(start,end);
    int* it = end;
    int bruh = *(end+1);
    while(it >= start){
        if(*it > bruh){
            *(it + 1) = *it;
            *it = bruh;
        }
        else{
            break;
        }
        it--;
    }
}

int main(){
    int bruh [5] = {8,3,7,5,6};
    insertsort(bruh, bruh + 5);
    for(int i = 0; i < 5; i++)
        cout<<bruh[i]<<endl;
}