class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int size = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>>res;

        for(int i =0 ;i <size; i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;

            for(int l = i+1 ; l < size ; l++){
                if(l  > i+1 && arr[l] == arr[l-1]) continue;
                int j = l+1, k =size-1;

                while(j< k){
                    long long sum = arr[i];
                    sum+=arr[j];
                    sum+=arr[k];
                    sum+=arr[l];

                    if(sum == target){
                        res.push_back({arr[i],arr[j],arr[k], arr[l]});
                        j++;
                        k--;
                        while(j < k && arr[j] == arr[j-1]) j++;
                        while(j <k && arr[k] == arr[k+1]) k--;
                    }
                    else if(sum > target){
                        k--;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        return res;
    }
};
