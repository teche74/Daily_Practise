class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int size = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0 , high = nums[size-1] - nums[0], res=  0;

        while(low <= high){
            int mid = low + (high - low)/2;

            int count_left = 0;
            int start = 0;

            for (int i = 0; i < size; ++i) {
                while (start < size && nums[i] - nums[start] > mid) {
                    ++start;
                }
                count_left += i - start;
            }

            if(count_left < k)
            {
                low = mid+1;
            }
            else{
                res = mid;
                high = mid-1;
            }
        } 

        return res;
    }
};