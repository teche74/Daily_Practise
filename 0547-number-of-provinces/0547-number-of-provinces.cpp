class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        int size = g.size();

        vector<int>vis(size+1,false);  

        // function<void(int)> bfs = [&](int curr){
        //     queue<int>q;

        //     q.push(curr);

        //     while(!q.empty()){
        //         int front = q.front();
        //         q.pop();

        //         for(int i = 0; i < g[front-1].size(); i++){
        //             if(g[front-1][i] == 1 && !seen[i+1]){
        //                 seen[i+1]= true;
        //                 q.push(i+1);
        //             }
        //         }
        //     }
        // };

        function<void(int)> dfs = [&](int curr){
            vis[curr] = true;

            for(int i = 0; i < g[curr-1].size(); i++){
                if(g[curr-1][i] == 1 && !vis[i+1]){
                    vis[i+1]= true;
                    dfs(i+1);
                }
            }
        };


        int count = 0;

        for(int i = 1 ; i <= size; i++){
            if(!vis[i]){
                count++;
                dfs(i);
            }
        }
        
        return count;
    }
};