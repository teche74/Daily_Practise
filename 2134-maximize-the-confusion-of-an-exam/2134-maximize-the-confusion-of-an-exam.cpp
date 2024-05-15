class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int size = a.size();

        int low = 0, high = 0;

        int t = 0, f = 0;

        int res = 0;

        while (high < size) {
            if (a[high] == 'T') t++;
            else f++;

            int maxi = max(t, f);
            int val = t + f;

            if (val - maxi <= k) {
                res = max(res, val);
            }
            else {
                while (val - maxi > k) {
                    if (a[low] == 'T') t--;
                    else f--;

                    low++;
                    val = t + f;
                    maxi = max(t, f);
                }

                res = max(res, val); 
            }

            high++;
        }

        return res;
    }
};
