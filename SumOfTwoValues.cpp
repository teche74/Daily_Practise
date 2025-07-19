#include<bits/stdc++.h>
using namespace std;

int main(){
    long long size , target;

    while(cin >> size >> target){
        vector<long long>values(size,0);

        for(long long i = 0; i < size; i++){
            cin >> values[i];
        }

        map<long long,long long>map;
        bool found = false;

        for(long long i = 0 ; i < size; i++){
            long long remain = target - values[i];

            if(map.find(remain) != map.end()){
                cout<<map[remain]+1 <<" "<<i+1<<endl;
                found = true;
                break;
            }

            map[values[i]]= i;
        }

        if(!found){
            cout<<"IMPOSSIBLE"<<endl;
        }

    }

    return 0;
}