class Solution {
public:
    int lengthLongestPath(string input) {
        // ye pichle mile files ki length store krega.
        unordered_map<int, int> map;

        // index le jisse traverse krega or ek ans store krale;
        int ind = 0, ans = 0;

        map[0] = -1;

        // ab dekh traverse krni he puri string, hit he 
        while (ind < input.size()) {
            // kinte andr jara hun directory ke vo ye count btayega.
            int count = 0;

            // me khta jab bhi '\n' ya '\t' hit hoga to level bdhega bole to nested directory.
            while (ind < input.size() && (input[ind] == '\n' || input[ind] == '\t')) {
                // chlta jaa ruk mat
                ind++;
                count++;
            }

            // ab soch agr nestd hui ni tab to current hi rh 
            if (count == 0) count = 1;
            int word_len = 0;
            bool file_exist = false;

            // ab tab tak pdh jab tak '\n' na hit ho 
            while (ind < input.size() && input[ind] != '\n') {
                word_len++;

                // dekh file hogi to definitely period ('.') hoga
                if (input[ind] == '.') file_exist = true;

                ind++;
            }

            // yahaan map mein count aur word length store karna hai
            map[count] = word_len + 1 + map[count - 1];

            // agar file exist karti hai to answer ko update karo
            ans = file_exist ? max(ans, map[count]) : ans;
        }

        return ans;
    }
};
