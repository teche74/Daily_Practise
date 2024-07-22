class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), [&](vector<int> &a , vector<int> & b){
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]; 
        });

        vector<vector<int>>res;

        for(int i =0 ;i < people.size() ; i++){
            int pos = people[i][1];

            res.insert(res.begin() + pos , people[i]);
        }
        return res;
    }
};