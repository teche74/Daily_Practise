class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ease;

        int rows = mat.size() , cols = mat[0].size();

        for(int i = 0 ;i  <rows; i++){
            int index = cols;

            for(int j = cols ; j>= 1; j/=2){
                while(index- j >= 0 && mat[i][index- j] <=0 ) index -=j;
            }

            ease.push_back({cols - index , i});
        }

        sort(ease.begin(),ease.end(), [](pair<int, int> & a , pair<int,int>& b){
           if (a.first != b.first) 
                return a.first > b.first;
            return a.second < b.second;
        });

        vector<int>res;

        for(int i =0 ;i  < k; i++){
            res.emplace_back(ease[i].second);
        }
        
        return res;
    }
};