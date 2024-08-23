class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>res;

        for(auto t : operations){
            if(t == "+"){
                res.emplace_back(res.back() + res[res.size()-2]);
            }
            else if(t == "C"){
                res.pop_back();
            }
            else if(t == "D"){
                res.emplace_back(res.back() * 2);
            }
            else{
                res.emplace_back(stoi(t));
            }
        }
        return res.empty() ? 0 : ::accumulate(res.begin(),res.end(),0);
    }
};