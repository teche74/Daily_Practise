#include <bits/stdc++.h>
using namespace std;


int main()
{
    int size;

    while(cin >> size){
        vector<int>nums(size, 0);

        for(int i = 0; i < size ; i++){
            cin >> nums[i];
        }

        long long sum = 0 , res = INT_MIN;

        for(auto t : nums){
            sum += t;

            if(sum < t){
                sum = t;
            }

            res = max(res , sum);
        }

        cout<<res<<endl;
    }
    return 0;
}