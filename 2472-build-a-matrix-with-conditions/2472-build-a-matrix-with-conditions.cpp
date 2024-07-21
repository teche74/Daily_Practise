class Solution {
public:
    unordered_map<int,int>helper(vector<vector<int>>arr,int n){
        vector<int>adj[n];
        vector<int>indeg(n,0);
        unordered_map<int,int>ump;
        int i= 0;
        for(auto it:arr){
            adj[it[0]-1].push_back(it[1]-1);
            indeg[it[1]-1]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int topp = q.front();
            ump[topp]=i;
            i++;
            q.pop();
            for(auto it:adj[topp]){
                indeg[it]--;
                if(indeg[it]==0){
                    
                    q.push(it);
                }
            }
        }
        return ump;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& arr1, vector<vector<int>>& arr2) {
        vector<vector<int>>ans(k,vector<int>(k,0));

        unordered_map<int,int>ump1 = helper(arr1,k);
        if(ump1.size()!=k) return {};
        unordered_map<int,int>ump2 = helper(arr2,k);
        if(ump2.size()!=k) return {};

        for(int i=0;i<k;i++){
            int row = ump1[i];
            int col = ump2[i];
            ans[row][col] = i+1;
        }
        return ans;
    }
};