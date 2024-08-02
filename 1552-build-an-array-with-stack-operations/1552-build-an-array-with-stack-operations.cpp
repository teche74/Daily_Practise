class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        vector<string>res;

        int prev = -1;

        for(int i = 0; i < target.size() ; i++){
            if(prev != -1){
                int diff = target[i] - prev - 1;

                for(int i = 0; i<diff ; i++){
                    res.emplace_back("Push");
                }

                for(int i = 0; i <diff ; i++){
                    res.emplace_back("Pop");
                }
                res.emplace_back("Push");
            }
            else{
                res.emplace_back("Push");
            }
            prev = target[i];
        }

        return res;
    }
};