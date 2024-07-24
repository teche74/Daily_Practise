class Solution {
public:
    void merge(vector<int> & nums , int low,  int mid, int high ){
        vector<int>temp(high - low+1,0);

        int i = low , j = mid+1 , k=0;

        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++];
            }
            else{
                temp[k++] = nums[j++];
            }
        }

        while(i <= mid){
            temp[k++] = nums[i++];
        }

        while(j <= high){
            temp[k++] = nums[j++];
        }

        for(int i =0; i < k ;i++){
            nums[i+low] = temp[i];
        }
    }
    void solve(vector<int> & nums, int low, int high){
        if(low >= high) return;

        int mid = low + (high - low)/2;

        solve(nums,low, mid);
        solve(nums, mid+1,high);
        merge(nums,low,mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();

        solve(nums,0 , size-1);

        return nums;
    }
};