class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        int size = nums.size() , index = 0;

        for(int x : nums){
            int remain = target - x;

            if(map.find(remain) != map.end()){
                return {map[remain], index};
            }

            map[x] = index++; 
        }

        return {-1,-1};
    }
};