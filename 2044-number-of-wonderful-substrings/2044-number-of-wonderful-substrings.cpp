class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int map[1024];
        memset(map,0, sizeof(map));

        int prefix_xor = 0;
        long long res = 0;
        map[0] =1;

        for(char ch : word){
            prefix_xor ^= 1 <<(ch - 'a'); // index ka xor krke mask create .

            // agr mask exist krta he to uski frequency useful he
            res += map[prefix_xor];

            for (int i = 0; i < 10; ++i) {
                res += map[prefix_xor ^ (1 << i)];
            }

            map[prefix_xor]++;
        }

        return res;
    }
};