class Solution {
public:
    void merge(vector<pair<int,int>> & arr , int low, int mid , int high, vector<int> & res){
        int i = low , j = mid+1;

        vector<pair<int,int>>temp(high - low + 1);

        i= low , j = mid+1;
        int k = 0;

        while(i<=mid && j <=high){
            if(arr[i].first  <= arr[j].first){
                temp[k++] = arr[j++];
            }
            else{
                res[arr[i].second] +=(high - j+1);
                temp[k++] = arr[i++];
            }
        }

        while(i <= mid){
            temp[k++] = arr[i++];
        }

        while(j <= high){
            temp[k++] = arr[j++];
        }
         

        for(int i =0; i < k ; i++){
            arr[low + i] = temp[i];
        }
    }
    void solve(vector<pair<int,int>>  & arr, int low, int high , vector<int> & res){
        if(low < high){
            int mid = low + (high - low)/2;

            solve(arr, low, mid, res);
            solve(arr, mid+1, high ,res);
            merge(arr, low, mid, high, res);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {

        vector<pair<int,int>>mod;
        int size = nums.size();
        vector<int>res(size,0);

        for(int i =0; i <size; i++){
            mod.push_back({nums[i],i});
        }

        solve(mod, 0, size-1, res);

        return res;
    }
};