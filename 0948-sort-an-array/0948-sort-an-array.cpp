class Solution {
public: 
    void solve(vector<int> & nums , int low, int mid, int high){
        int i = low , j = mid+1, size = nums.size(), k=0;

        vector<int> temp(high - low+1,0);

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }

        while(i<=mid){
            temp[k++] = nums[i++];
        }

        while(j<=high){
            temp[k++] = nums[j++];
        }

        for(int i = 0; i< k ; i++){
            nums[low + i] = temp[i];
        }
    }
    void helper(vector<int> & nums, int low , int high){
        if(low >= high) return ;

        int mid = low + (high - low)/2;

        helper(nums,low, mid);
        helper(nums, mid+1,high);
        solve(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        helper(nums,0 , nums.size()-1);
        return nums;
    }
};