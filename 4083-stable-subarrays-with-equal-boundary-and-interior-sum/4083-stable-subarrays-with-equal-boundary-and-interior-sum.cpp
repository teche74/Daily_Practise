class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        vector<long long>prefix;

        for(int x : capacity){
            prefix.push_back(x + (!prefix.empty() ? prefix.back() : 0)); 
        }


        int low = 0, high = 0 , size = capacity.size() ,  res = 0;

        for (int l = 0; l < size - 2; l++) {
            for (int r = l + 2; r < size; r++) {
                long long sum = prefix[r-1] - prefix[l];
                if (capacity[l] == capacity[r] && capacity[l] == sum)
                    res++;
            }
        }
        
        return res;
    }
};