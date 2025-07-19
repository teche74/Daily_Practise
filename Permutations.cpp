#include<bits/stdc++.h>
using namespace std;

int main(){
    int limit;

    while(cin >> limit){
        if(limit == 3 || limit == 2 ){
            cout<<"NO SOLUTION"<<endl;
            continue;
        }
        for(int i = 2 ; i <= limit ; i+=2) cout<<i<<" ";
        for(int i = 1; i <= limit ; i+=2) cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}