class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long>st;
        int size = nums.size();

        int low = 0 , high = 0;


        while(high < size){

            while(high - low  > indexDiff){
                st.erase(nums[low]);
                low++;
            }

            auto it = st.lower_bound((long long)nums[high] - valueDiff);
            if(it != st.end() &&  *it <= nums[high] + valueDiff) return true;
            st.insert(nums[high]);
            high++;
        }

        return false;
    }
};