class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int low = 0 , high = 0, size = cards.size() , res  = INT_MAX;

        unordered_map<int,int>map;

        while(high < size){
            map[cards[high]]++;

            while(map[cards[high]] >= 2){
                res = min(res, high - low + 1);
                map[cards[low]]--;
                low++;
            }

            high++;
        }

        return res == INT_MAX ? -1  : res ;
    }
};