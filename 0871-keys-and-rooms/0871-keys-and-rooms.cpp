class Solution {
public:
    void solve(int curr , vector<vector<int>>map, vector<bool> & vis, int  & rem){
        
        for(auto t : map[curr]){
            if(!vis[t]){
                vis[t] = true;
                rem--;
                solve(t,map,vis,rem);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);

        vis[0]= true;

        int remain = n-1; 

        solve(0,rooms,vis,remain);

        return remain == 0;
    }
};