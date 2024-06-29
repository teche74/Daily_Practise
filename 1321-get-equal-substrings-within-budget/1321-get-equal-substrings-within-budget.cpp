class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int low = 0 , high = 0 , size = s.size(), cost = 0, res = 0;

        while(high < size) {
            cost += abs(s[high] - t[high]);

            while(cost > maxCost){
                cost-=abs(s[low] - t[low]);
                low++; 
            }
            res = max(res, high - low + 1);
            high++;
        }
        return res;
    }
};