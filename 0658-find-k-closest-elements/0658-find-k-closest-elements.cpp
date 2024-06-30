class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int size = arr.size(); 
        
        vector<int>pre(size,0);

        for(int i =0; i < size ; i++){
            pre[i] = abs(arr[i] - x); 
        }

        int low = 0 , high = 0  , diff = INT_MAX, sum = 0, ind1 = -1 , ind2= -1 ;

        while(high < size){
            sum += pre[high] ;

            while(high - low + 1 > k){
                sum-=pre[low];
                low++;
            }

            if(sum < diff && high - low +1 == k){
                diff = sum;
                ind1 = low;
                ind2 = high; 
            }
            high++;
        }

        vector<int>res;

        for(int i = ind1; i<= ind2 ;i++){
            res.emplace_back(arr[i]);
        }

        return res;
    }
};