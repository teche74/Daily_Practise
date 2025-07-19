#include<bits/stdc++.h>
using namespace std;

int main(){
    long long size , opers;

    while(cin >> size >> opers){
        vector<long long>nums(size, 0);
        unordered_map<long long,long long>map , index_map;

        for(long long i = 0; i < size; i++){
            cin >> nums[i];
            map[nums[i]] = i;
            index_map[i] = nums[i];
        }

        sort(nums.begin() , nums.end());
        
        long long index1 = 0, index2 = 0;
        long long round = 1;
        

        for(auto val : nums){
            if(map[val] < map[val-1]){
                round++;
            }
        }

        bool add = false;

        while(opers--){
            cin >> index1 >> index2;
            if(index_map[index1-1] > index_map[index2-1]){
                add = false;
            }
            else{
                add = true;
            }
            cout<<round + (add  ? 1 : -1)<<endl;
        }
        
    }
    return 0;
}