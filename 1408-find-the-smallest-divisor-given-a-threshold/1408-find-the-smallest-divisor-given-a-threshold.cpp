class Solution {
public:
    int Check(vector<int> & nums, int div){
        int sum = 0;

        for(int x : nums){
            sum +=  (x + div-1) /div;
        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 , high = *max_element(nums.begin(), nums.end());

        while(low <= high){
            int mid = low  + (high - low )/2;

            if(Check(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};