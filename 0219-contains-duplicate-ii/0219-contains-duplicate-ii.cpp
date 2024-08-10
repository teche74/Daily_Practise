class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int,int>>temp;

        for(int i = 0 ; i < nums.size() ; i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end());

        for(int i = 1; i <temp.size(); i++){
            if(temp[i].first == temp[i-1].first && abs(temp[i].second - temp[i-1].second) <= k) return true;
        }
        return false;
    }
};