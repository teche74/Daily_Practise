class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        int size = arr.size();

        sort(arr.begin(), arr.end());

        vector<vector<int>>res;

        for(int i =0 ;i <size; i++){
            if(i > 0 && arr[i] == arr[i-1]) continue;

            int j = i+1, k =size-1;

            while(j< k){
                int sum = arr[i] + arr[j] + arr[k];

                if(sum == 0){
                    res.push_back({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                    while(j < k && arr[j] == arr[j-1]) j++;
                    while(j <k && arr[k] == arr[k+1]) k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};