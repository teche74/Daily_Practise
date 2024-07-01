class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target  = ::accumulate(nums.begin(), nums.end(),0) - x;

        if(target < 0 ) return -1;
        if(target ==  0) return nums.size();

        unordered_map<int,int>sum_map;
        sum_map[0] = -1;

        int curr = 0, res = -1, size = nums.size();

        for(int i =0 ;i < size; i++){
            curr+=nums[i];

            if(sum_map.find(curr - target) != sum_map.end()){
                res = max(res, i - sum_map[curr - target]);
            }
            sum_map[curr] = i;
        }

        return res == -1 ? -1 : size - res;
    }
};