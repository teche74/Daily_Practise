class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        long long low = 0,  high = 0 , size = nums.size(), count  = 0 , res = 0;

        while(high < size){
            count+=map[nums[high]];
            map[nums[high]]++;

            while(count >= k){
                res += size - high;
                map[nums[low]]--;
                count-=(map[nums[low]]);
                low++;
            }
            high++;
        }
        return res;
    }
};