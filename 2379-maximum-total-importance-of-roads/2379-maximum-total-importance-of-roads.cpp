class Solution {
public:
    long long maximumImportance(int size, vector<vector<int>>& roads) {
        vector<int>deg(size,0);


        for(auto t : roads){
            deg[t[0]]++;
            deg[t[1]]++;
        }


        sort(deg.begin(),deg.end());

        long long res = 0;

        for(int i =0 ;i < size ; i++){
            res += (1LL * (i+1)) * deg[i];
        }

        return res;
    }
};