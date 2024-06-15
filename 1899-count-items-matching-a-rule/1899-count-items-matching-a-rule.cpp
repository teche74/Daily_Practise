class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ind = ruleKey == "type" ? 0 : ruleKey == "color" ? 1 : 2;

        int matched = 0;

        for(auto t  : items){
            if(t[ind] == ruleValue) matched++;
        }

        return matched;
    }
};