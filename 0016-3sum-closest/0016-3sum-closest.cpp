class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());

        int size = arr.size();
        int res = 0 , min_diff = INT_MAX;

        for(int i =0; i <size ; i++){
            if( i > 0 && arr[i] == arr[i-1]) continue;            

            int j = i+1;
            int k = size-1;

            while(j < k ){
                int sum = arr[i] + arr[j] + arr[k];

                if(sum == target) return sum;

                else if(sum > target){
                    k--;
                }
                
                else{
                    j++;
                }

                if(abs(sum - target) < min_diff){
                    min_diff = abs(sum - target);
                    res  = sum;
                }
            }

        }

        return res;
    }
};