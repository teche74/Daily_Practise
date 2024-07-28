class AuthenticationManager {
public:
    int live;
    unordered_map<string , int >expire_map;
    map<int , string> time_map;
    AuthenticationManager(int timeToLive) {
        live  = timeToLive; 
    }
    
    void generate(string tokenId, int currentTime) {
        int expire  = currentTime + live;
        expire_map[tokenId] = expire;
        time_map[expire] = tokenId;
    }
    
    void renew(string tokenId, int currentTime) {
        if(expire_map.find(tokenId) != expire_map.end() && expire_map[tokenId] > currentTime){
            int prev_time = expire_map[tokenId];
            time_map.erase(prev_time);
            int new_time = currentTime + live;
            expire_map[tokenId] = new_time;
            time_map[new_time] = tokenId;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it = time_map.lower_bound(currentTime + 1);
        return distance(it, time_map.end());
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */