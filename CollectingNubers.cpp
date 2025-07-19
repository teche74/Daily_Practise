#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;

    while(cin >> size){
        vector<int>nums(size, 0);
        unordered_map<int,int>map;

        for(int i = 0; i < size; i++){
            cin >> nums[i];
            map[nums[i]] = i;
        }

        int round = 1;
        sort(nums.begin() , nums.end());

        for(auto val : nums){
            if(map[val] < map[val-1]){
                round++;
            }
        }

        cout<<round<<endl;
    }
    return 0;
}