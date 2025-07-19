#include<bits/stdc++.h>
using namespace std;

long long solve(long long size){
    long long total_ways = (size * size) *((size * size)-1);
    long long duplicate_config_removed = total_ways >> 1;
    long long knight_attacks = 4*((size-1)*(size-2));

    return duplicate_config_removed - knight_attacks;
}

int main(){
    long long n;

    while(cin >> n){
        for(long long i = 1 ; i <= n ; i++){
            cout<<solve(i)<<endl;
        }
    }
    return 0;
}