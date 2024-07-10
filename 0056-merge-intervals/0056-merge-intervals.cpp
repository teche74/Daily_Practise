class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<vector<int>>res;

        res.push_back(intervals[0]);

        for(int i =1; i <size ;){
            if(res.back()[1] >= intervals[i][0]){
                int new_end = res.back()[1];
                while( i < size && new_end >= intervals[i][0]){
                    new_end = max(new_end , intervals[i][1]);
                    i++;
                }
                res.back()[1] = new_end;
                if(i == size) break;
            }
            else{
                res.push_back(intervals[i]);
                i++;
            }
        }
        return res;
    }
};