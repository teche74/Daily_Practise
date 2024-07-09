class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto solve = [&]()->vector<int>{
            int size = nums.size();
            unordered_map<int,int>map;

            for(int i = 0; i < size;  i++){
                int comp = target -nums[i];

                if(map.find(comp)!= map.end()){
                    return {i, map[comp]};
                }   
                else{
                    map[nums[i]]= i;
                }
            }
            return {-1,-1};
        };

        return solve();
    }
};