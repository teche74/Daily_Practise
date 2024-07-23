class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int in[n+1] , out[n+1];
        memset(in, 0,sizeof(in));
        memset(out, 0 ,sizeof(out));

        for(auto t : trust){
            out[t[0]]++;
            in[t[1]]++;
        }

        for(int i = 1 ;i <= n ;i++){
            if(in[i] == n-1 && out[i] == 0) return i;
        }
        return -1;
    }
};