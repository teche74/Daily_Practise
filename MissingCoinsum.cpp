#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;

    while(cin >> size){
        vector<int>nums(size,0);

        for(int i = 0; i < size ;  i++){
            cin >> nums[i];
        }

        sort(nums.begin() , nums.end());

        long long curr_sum = 1;

        for(int val : nums){
            if(val > curr_sum){
                break;
            }
            curr_sum += val;
        }

        cout<<curr_sum<<endl;
    }
    return 0;
}