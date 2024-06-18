class Solution {
public:
    int check(vector<int>nums, int val){
        int sum = val;
        for (int x : nums) {
            sum += x;
            if (sum <= 0)
                return sum;
        }
        return sum;
    }
    int minStartValue(vector<int>& nums) {
        int low =1 , high= 0 ;

        for(int x : nums){
            high += abs(x);
        }  

        high++;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(nums,mid) <= 0){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};