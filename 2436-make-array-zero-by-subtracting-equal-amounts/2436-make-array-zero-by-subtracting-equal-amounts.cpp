class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>map;

        int size = nums.size();

        for(int i = 0 ;i  < size ; i++){
            if(nums[i] > 0)
                map[nums[i]]++;
        }

        return map.size();
    }
};