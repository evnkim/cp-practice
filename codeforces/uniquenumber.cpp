/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: evan.e.1
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i =0; i < t; i++){
        int x;
        cin>>x;
        if(x <= 9){
            cout<<x<<endl;
        }
        else if( x<= 17){
            cout<<x-9<<9<<endl;
        }
        else if( x<= 24){
            cout<<x-17<<89<<endl;   
        }
        else if( x<= 30){
            cout<<x-24<<789<<endl;
        }
        else if( x<= 35){
            cout<<x-30<<6789<<endl;
        }
        else if( x<= 39){
            cout<<x-35<<56789<<endl;
        }
        else if( x<= 42){
            cout<<x-39<<456789<<endl;
        }
        else if( x<= 44){
            cout<<x-42<<3456789<<endl;
        }
        else if( x<= 45){
            cout<<123456789<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}