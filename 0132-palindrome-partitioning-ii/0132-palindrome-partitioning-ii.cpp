class Solution {
public:
    bool Palli(const string  & s, int low, int high){
        while(low<high){
            if(s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    int solve(const string  & s , int low, int high, vector<vector<int>> & map){

        if(map[low][high] != -1) return map[low][high];

        if(Palli(s, low, high)) {
            map[low][high] = 0;
            return 0;
        }

        int cuts = INT_MAX;

        for(int i=low; i < high ; i++){
            if(Palli(s,low, i))
                cuts = min(cuts , 1 + solve(s, i+1, high,map)); 
        }

        map[low][high] = cuts;

        return map[low][high];
    }
    int minCut(string s) {
        int size = s.size();

        vector<vector<int>> arr(size, vector<int>(size, -1));

        return solve(s, 0, s.size()-1, arr);
    }
};