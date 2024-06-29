class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low =  0 , high = 0 , size = nums.size(), res = 0;
        int count = 0;

        while(high < size){
            count +=(nums[high] == 0);

            while(count > k ){
                count -=(nums[low] == 0);
                low++;
            }

            
            res = max(res, high - low+1);
            high++;
        }

        return res;
    }
};