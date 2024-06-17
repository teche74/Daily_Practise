class Solution {
public:
    bool check(string s, string p)
    {
        unordered_set<char>st1(s.begin(),s.end());
        unordered_set<char>st2(p.begin(),p.end());

        return st1== st2;
    }
    int similarPairs(vector<string>& words) {
        int size = words.size();
        int count =0;
        for(int i = 0; i < size ; i++){
            for(int j = i +1; j < size; j++){
                if(check(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};