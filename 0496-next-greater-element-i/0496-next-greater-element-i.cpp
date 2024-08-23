class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        stack<int>st;

        int size = nums2.size();

        for(int i = size-1; i>= 0; i-- ){
            while(st.size() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                map[nums2[i]] = -1;
            }
            else{
                map[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int>res;
        for(auto t : nums1){
            res.emplace_back(map[t]);
        }
        return res;
    }
};