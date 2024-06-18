class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        
        for(auto x:logs)
        {
            if(x=="../")
            {
                if(!s.empty())
                    s.pop();
            }
            else if(x!="./")
                s.push("+");
        }
        return s.size();
    }
};