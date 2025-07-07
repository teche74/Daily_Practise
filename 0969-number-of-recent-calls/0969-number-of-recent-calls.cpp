class RecentCounter {
public:
    priority_queue<int, vector<int>, greater<int>>heap;

    RecentCounter() {   
    }
    
    int ping(int t) {
        heap.push(t);

        while(heap.size() && heap.top() < t - 3000){
            heap.pop();
        }
        return heap.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */