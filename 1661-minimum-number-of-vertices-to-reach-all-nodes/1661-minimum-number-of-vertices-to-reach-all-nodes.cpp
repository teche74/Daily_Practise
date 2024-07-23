class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>in(n,0);

        for(auto t : edges){
            in[t[1]]++;
        }

        vector<int>res;

        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                res.emplace_back(i);
            }
        }
        return res;
    }
};