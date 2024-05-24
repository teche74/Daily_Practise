class Solution {
public:
    int helper(vector<int> & nums, int k){
        int low= 0 , high = 0 ,size = nums.size(), count = 0, res= 0;
        unordered_map<int,int>map;

        while(high < size){
            map[nums[high]]++;
            count += (map[nums[high]] == 1);

            while(count > k){
                map[nums[low]]--;
                count-=(map[nums[low]] == 0);
                low++;
            }
            res += high-low+1;
            high++;
        }

        return res;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int k = st.size();
        return helper(nums,k) - helper(nums, k-1);
    }
};