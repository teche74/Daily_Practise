class Solution {
public:
    int shelf;
    int dp[1001][1001];
    int solve(int index , int height ,vector<vector<int>> & books, int remain ){
        if(remain < 0) return 1e9;
        
        if(index >= books.size()){
            return height;
        }

        if(dp[index][remain]!= -1) return dp[index][remain];

        int curr = solve(index+1,max(height,books[index][1]) , books, remain - books[index][0]);

        int next = height  + solve(index+1,books[index][1],books ,shelf - books[index][0]);


        return dp[index][remain] = min(curr,next) ;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        shelf =shelfWidth;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,books,shelfWidth);
    }
};