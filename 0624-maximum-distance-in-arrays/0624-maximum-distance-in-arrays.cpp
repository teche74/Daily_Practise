class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int size = arrays.size() ,res = 0;

        int mini = arrays[0][0] , maxi = arrays[0][arrays[0].size()-1];


        for(int i = 1; i < size ; i++){
            res = max(res, max(arrays[i].back() - mini , maxi - arrays[i][0]));
            mini = min(mini,arrays[i][0]);
            maxi = max(maxi , arrays[i].back());
        }

        return res;
    }
};