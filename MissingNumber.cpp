#include<bits/stdc++.h>
using namespace std;


int main(){
    long long size;

    while(cin >> size){
        vector<long long>temp(size-1, 0);

        for(long long i = 0 ;i  < size-1; i++){
            cin >> temp[i];
        }

        long long sum = ::accumulate(temp.begin() , temp.end() , 0L);
        long long total = (size * ( size + 1)) >> 1;

        cout<<total - sum<<endl;
    }

    return 0;
}