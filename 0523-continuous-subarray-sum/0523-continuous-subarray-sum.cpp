class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<long long ,int>mp;
        int sum=0;

        mp[0] = -1;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];

            if(k != 0 ){
                sum%=k;
            }

            auto it = mp.find(sum);

            if(it != mp.end()){
                if(i - it->second  >= 2){
                    return true;
                }
            } 
            else{
                mp[sum] = i;
            }
        }
        return false;
    }
};