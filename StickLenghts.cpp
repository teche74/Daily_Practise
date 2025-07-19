#include<bits/stdc++.h>
using namespace std;

int main(){
    long long size;

    while(cin >> size){
        vector<long long>lengths(size,0);

        for(long long i = 0; i < size ; i++){
            cin >> lengths[i];
        }

        sort(lengths.begin() , lengths.end());

        long long avg_len = lengths[size / 2];
        long long res = 0;

        for(auto len : lengths){
            res += abs(avg_len - len);
        }

        cout<<res<<endl;
    }
    return 0;
}