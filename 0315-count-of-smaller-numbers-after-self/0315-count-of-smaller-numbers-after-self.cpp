class Solution {
public:
    void merge(int low, int mid, int high , vector<pair<int, int>>&nums, vector<int> & res){

        vector<pair<int,int>>temp(high - low+1);

        int i = low  , j = mid+1;
        int k =0 ;

        while(i <= mid && j <= high){
            if(nums[i].first <= nums[j].first){
                temp[k++] = nums[j++];
            }
            else{
                res[nums[i].second] += high - j + 1; 
                temp[k++] = nums[i++];
            }
        }

        while(i<=mid){
            temp[k++] = nums[i++];
        }

        while(j<=high){
            temp[k++] = nums[j++];
        }

        for(int i =0 ;i < k ; i++){
            nums[low+ i]  = temp[i];
        }
    }
    void helper(int low, int high,vector<pair<int, int>>& nums, vector<int> & temp){
        
        if(low < high){
            int mid = low + (high - low)/2;

            helper(low, mid, nums,temp);
            helper(mid+1,high , nums,temp);

            merge(low, mid, high , nums,temp);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        vector<int>temp(size,0);
        vector<pair<int, int>> arr;
        
	    for(int i = 0; i < size; i++)
	    {
	        arr.push_back({nums[i], i});
	    }

        helper(0 , size-1, arr,temp);
        return temp;
    }
};