#include<bits/stdc++.h>
using namespace std;

int main(){
    int size , val;
    
    while(cin >> size){
        map<long long, int>mp;

        for(int i = 0 ; i < size ; i++){
            cin >> val;
            mp[val]++;
        }


        cout<<mp.size()<<endl;
    }
    return 0;
}