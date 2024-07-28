class Solution {
public:
    long long merge(int low, int mid, int high , vector<int> & diff, int d){
        int j  = mid+1, i =low;
        long long count = 0;
        while(i<=mid && j<=high){
            if(diff[i]<=(diff[j]+d)) 
            {
                count += (high - j + 1);
                i++;
            }
            else     
            {
                j++;
            }
        }

        vector<int>temp(high - low+1,0);

        i = low  , j = mid+1;
        int k =0 ;

        while(i <= mid && j <= high){
            if(diff[i] <= diff[j]){
                temp[k++] = diff[i++];
            }
            else{
                temp[k++] = diff[j++];
            }
        }

        while(i<=mid){
            temp[k++] = diff[i++];
        }

        while(j<=high){
            temp[k++] = diff[j++];
        }

        for(int i =0 ;i < k ; i++){
            diff[low+ i]  = temp[i];
        }

        return count;
    }
    long long helper(int low, int high,vector<int>& diff_arr, int diff){
        long long count = 0; 
        if(low < high){
            int mid = low + (high - low)/2;

            count += helper(low, mid, diff_arr, diff);
            count += helper(mid+1,high , diff_arr, diff);

            count+= merge(low, mid, high , diff_arr, diff);
        }
        return count;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int size = nums1.size();
        vector<int>diff_arr(size,0);

        for(int i = 0 ;i <size; i++){
            diff_arr[i] = nums1[i] - nums2[i];
        }

        return helper(0 , size-1, diff_arr, diff);   
    }
};