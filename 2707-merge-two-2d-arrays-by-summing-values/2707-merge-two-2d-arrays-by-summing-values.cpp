class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>map;

        for(int i =0; i < nums1.size() ; i++){
            map[nums1[i][0]] = nums1[i][1]; 
        }

        for(int i =0; i < nums2.size() ;i++){
            map[nums2[i][0]]+= nums2[i][1];
        }

        vector<vector<int>>res;

        for(auto t : map){
            res.push_back({t.first,t.second});
        }

        sort(res.begin(),res.end());

        return res;
    }
};