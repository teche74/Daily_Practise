class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(),intervals.end());

        int size = intervals.size();

        vector<vector<int>>res;

        res.emplace_back(intervals[0]);

        for(int i= 1; i <size ;){
            while(i < size && res.back()[1]  >= intervals[i][0]){
                res.back()[1] = max(res.back()[1],intervals[i][1]);
                res.back()[0] = min(res.back()[0] , intervals[i][0]);
                i++;
            }
            if(i < size && res.back()[1]  <= intervals[i][0]){
                res.emplace_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};