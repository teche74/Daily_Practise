#include <bits/stdc++.h>
using namespace std;


long long solve(vector<int> & weights ,  int index, long long sum1, long long sum2, unordered_map<int,unordered_map<long long,unordered_map<long long,int>>> & dp){
    if(index >= weights.size()){
        return abs(sum1 - sum2);
    }

    if(dp.count(index) && dp[index].count(sum1) && dp[index][sum1].count(sum2)) return dp[index][sum1][sum2];

    return min(solve(weights , index+1, sum1 + weights[index] , sum2 , dp) , solve(weights , index+1 , sum1 , sum2 + weights[index], dp));
}


int main()
{
    long long apples;

    
    while(cin >> apples){
        vector<int>weights(apples, 0);
        
        for(int i = 0 ;i < apples ; i++){
            cin >> weights[i];
        }
        unordered_map<int,unordered_map<long long,unordered_map<long long,int>>>dp;

        long long res = solve(weights, 0, 0LL, 0LL, dp);
        cout<<res<<endl;
    }
    return 0;
}
