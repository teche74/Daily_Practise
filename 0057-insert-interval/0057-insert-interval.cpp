class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.emplace_back(newInterval);
        int size = intervals.size();

        sort(intervals.begin(), intervals.end());
        vector<vector<int>>res;

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