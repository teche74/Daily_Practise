class Solution {
public:
    long long helper(vector<int> & diffi , int low, int mid , int high , int diff){
        vector<int>temp(high-low+1,0);

        int i = low, j = mid+1,k = 0;
        long long count = 0;
        

        while(i <= mid && j <= high){
            if(diffi[i] <= diffi[j]  + diff){
                i++;
                count+= (high - j + 1);
            }
            else{
                j++;
            }
        }

        i = low , j = mid+1;

        while(i <=mid && j <= high){
            if(diffi[i] <= diffi[j]){
                temp[k++] = diffi[i++];
            }
            else{
                temp[k++] = diffi[j++];
            }
        }

        while(i <= mid){
            temp[k++] = diffi[i++];
        }

        while(j <= high){
            temp[k++] = diffi[j++];
        }

        for(int l = 0; l< k; l++){
            diffi[low + l] = temp[l];
        }

        return count;
    }

    long long solve(vector<int> & diffi , int low, int high , int diff){
        long long count  = 0;
        if(low < high){
            int mid = low + (high - low)/2;
            count+=solve(diffi,low,mid,diff);
            count+=solve(diffi,mid+1,high,diff);
            count+=helper(diffi,low, mid, high,diff);
        }
        return count;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int size = nums1.size();

        vector<int>diffi;

        for(int i = 0; i <size; i++){
            diffi.emplace_back(nums1[i] - nums2[i]);
            
        }

        return solve(diffi, 0 , size-1,diff);
    }
};