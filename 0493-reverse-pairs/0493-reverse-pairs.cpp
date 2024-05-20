class Solution {
public:
    void solve(vector<int> & arr, int low, int mid, int high , int  & count){
        int i = low, j = mid+1, k =0;
        vector<int>temp(high - low+1, 0);

        while(i <= mid &&  j <= high){
            if(arr[i] <= (long long)2 * arr[j]){
                i++;
            }
            else{
                count+=(mid - i +1);
                j++;
            }
        }

        i = low, j = mid+1;

        while(i<=mid &&  j<= high){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }

        while(j <= high){
            temp[k++] = arr[j++];
        }

        for(int i =0 ;i < k ;i++){
            arr[low + i] = temp[i]; 
        }
    }
    void helper(vector<int>&arr, int low ,int high, int  & count){
        if(low < high){
            int mid = low + (high - low)/2;

            helper(arr, low, mid, count);
            helper(arr,mid+1,high, count);

            solve(arr, low, mid, high, count);
        }
    }
    int reversePairs(vector<int>& nums) {
        int size = nums.size();

        int count  = 0;
        helper(nums,0, size-1, count);

        return count;
    }
};