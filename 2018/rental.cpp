#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

vector<int> cows;
vector<pair<int,int>> stores;
vector<int> farmers;

typedef pair<int,int> Point;
bool ycomp(Point p, Point q) { return p.second > q.second; }
bool reversecomp(int x, int y) { return x > y; }

int getStoreProfit(int g){
    int i = 0;
    int profit = 0;
    while(g > 0 && i < stores.size()){
        if(g >= stores[i].first){
            g -= stores[i].first;
            cout<<"selling: "<<stores[i].first<<" gallons at "<<stores[i].second<<endl;
            profit += stores[i].first * stores[i].second;
            i++;
        }
        else{
            cout<<"selling: "<<g<<" gallons at "<<stores[i].second<<endl;
            
            profit += g * stores[i].second;
            break;
        }
    }
    cout<<"found total of "<<profit<<endl;
    return profit;
}
void storeProfitRemove(int g){
    int i =0;
    while(g > 0 && stores.size() > 0){
        if(g >= stores[0].first){
            g -= stores[0].first;
            stores.erase(stores.begin());
            i++;
        }
        else{
            stores[i].first -= g;
            break;
        }
    }
}

int main(){

    ofstream fout ("rental.out");    
    ifstream fin ("rental.in");

    int N, M, R;
    fin>>N>>M>>R;

    

    for(int i = 0; i < N; i++){
        int c;
        fin>>c;
        cows.push_back(c);
    }
    for(int i = 0; i < M; i++){
        int q,p;
        fin>>q>>p;
        stores.push_back({q,p});
    }
    for(int i = 0; i < R; i++){
        int r;
        fin>>r;
        farmers.push_back(r);
    }
    sort(farmers.begin(),farmers.end(),reversecomp);
    sort(cows.begin(),cows.end(),reversecomp);
    sort(stores.begin(),stores.end(),ycomp);
    
    long long profit = 0;

    while(cows.size() >  0){
        if(stores.size() == 0 && farmers.size() == 0)
            break;
        int storeProfit = getStoreProfit(cows[0]);
        if(farmers[0] > storeProfit){
            profit += farmers[0];
            cout<<farmers[0]<<endl;
            farmers.erase(farmers.begin());
            cows.erase(cows.end() - 1);
        }
        else{
            storeProfitRemove(cows[0]);
            cows.erase(cows.begin());
            profit += storeProfit;
        }
        cout<<"PROFIT SO FAR: "<<profit<<endl;
        
    }
    fout<<profit;
}