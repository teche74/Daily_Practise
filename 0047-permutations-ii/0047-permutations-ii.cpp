class Solution {
public:
    void _next(vector<int>&arr){
        int index = -1, size = arr.size();

        for(int i =size-2; i >= 0 ; i--){
            if(arr[i] > arr[i+1]){
                index = i;
                break;
            }
        }

        if(index == -1){
            reverse(arr.begin(),arr.end());
            return;
        }

        for(int i = size-1; i>= 0 ;i--){
            if(arr[i] < arr[index]){
                swap(arr[i],arr[index]);
                break;
            }
        }

        reverse(arr.begin()+index+1,arr.end());
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;

        do{
            res.emplace_back(nums);
            _next(nums);
        }while(nums != res[0]);

        return res;
    }
};
