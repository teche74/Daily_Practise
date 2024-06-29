class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int low = 0 , high = 0 , size = nums.size() , res = 0 ;

        deque<int> mini, maxi;

        while(high < size){

            while(mini.size() && mini.back() > nums[high]){
                mini.pop_back();
            }

            mini.push_back(nums[high]);

            while(maxi.size() && maxi.back() < nums[high]){
                maxi.pop_back();
            }

            maxi.push_back(nums[high]);

            while ( mini.size() && maxi.size() && maxi.front() - mini.front() > limit) {
                if (nums[low] == mini.front()) {
                    mini.pop_front();
                }
                
                if (nums[low] == maxi.front()) {
                    maxi.pop_front();
                }
                low++;
            }

            res = max(res, high - low+1);
            high++;
        }
        return res;
    }
};