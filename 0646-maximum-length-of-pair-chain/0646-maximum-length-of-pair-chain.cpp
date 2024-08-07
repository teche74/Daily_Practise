class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();

        sort(pairs.begin(), pairs.end(),[&](vector<int>&a,vector<int>&b){
            if(a[1]==b[1])
                return a[0]<b[0];

            return a[1]<b[1];
        });

        int count = 1; 

        int prev = pairs[0][1];

        for(int i=1 ; i<size ; i++){
            if(pairs[i][0] > prev){
                count++;
                prev = max(prev,pairs[i][1]); 
            }
        }

        return count;
    }
};