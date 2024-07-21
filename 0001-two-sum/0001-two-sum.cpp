class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();

        unordered_map<int,int>map;

        for(int i = 0; i <size; i++){
            int comp = target - nums[i];

            auto it = map.find(comp);

            if(it != map.end()){
                return {it->second, i};
            }

                map[nums[i]] = i;
        }

        return {-1,-1};
    }
};