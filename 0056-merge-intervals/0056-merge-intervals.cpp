class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>>res;

        sort(intervals.begin(), intervals.end());

        res.emplace_back(intervals[0]);

        for(int i = 1 ; i < size ;i++){
            while(i  < size && res.back()[1] >= intervals[i][0]){
                res.back()[1] = max(res.back()[1] , intervals[i][1]);
                i++;
            }
            if(i < size && res.back()[1] < intervals[i][0]){
                res.emplace_back(intervals[i]);
            }
        }

        return res;
    }
};