class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();

        vector<bool>seen(size,false);

        seen[0] = true;

        queue<int>q;

        q.push(0);

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto t : rooms[front]){
                if(!seen[t]){
                    seen[t] = true;
                    q.push(t);
                }
            }
        }

        for(int i = 0; i < size; i++){
            if(!seen[i]) return false;
        }
        return true;
    }
};