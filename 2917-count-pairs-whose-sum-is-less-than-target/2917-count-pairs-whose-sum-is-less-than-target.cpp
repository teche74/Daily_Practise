class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;

        sort(nums.begin(), nums.end());

        int res= 0;

        while(low < high){
            int val = nums[low] +  nums[high];
            if(val < target){
                res +=(high - low);
                low++;
            }
            else{
                high--;
            }
        }
        return res;
    }
};