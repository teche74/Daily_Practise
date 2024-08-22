class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        set<long long> seen;  

        pq.push(1);
        seen.insert(1);
        
        long long ugly = 1;

        for (long long i = 1; i <= n; i++) {
            ugly = pq.top();
            pq.pop();

            if (seen.find(ugly * 2) == seen.end()) {
                pq.push(ugly * 2);
                seen.insert(ugly * 2);
            }
            if (seen.find(ugly * 3) == seen.end()) {
                pq.push(ugly * 3);
                seen.insert(ugly * 3);
            }
            if (seen.find(ugly * 5) == seen.end()) {
                pq.push(ugly * 5);
                seen.insert(ugly * 5);
            }
        }

        return ugly; 
    }
};
