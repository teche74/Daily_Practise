class RecentCounter {
public:
    unordered_map<int,int>map;

    RecentCounter() {
        map.clear();    
    }
    
    int ping(int t) {
        int curr_time = t;
        int last = t - 3000;
        
        if(last < 0){
            last = 0;
        }

        map[curr_time]++;

        int count = 0;

        for(auto t : map){
            if(t.first  >= last){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */