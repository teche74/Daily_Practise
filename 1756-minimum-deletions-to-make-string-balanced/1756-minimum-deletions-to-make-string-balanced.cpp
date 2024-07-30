class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.length();
        vector<int> a(n, 0), b(n, 0);

        for (int i = 1; i < n; i++) 
            a[i] = a[i - 1] + (s[i - 1] == 'b');

        for (int i = n - 2; i >= 0; i--) 
            b[i] = b[i + 1] + (s[i + 1] == 'a');


        int ans = min(b[0], a[n - 1]); 
        
        for (int i = 1; i < n; i++) 
            ans = min(ans, a[i] + b[i]);

        return ans;
    }
};
