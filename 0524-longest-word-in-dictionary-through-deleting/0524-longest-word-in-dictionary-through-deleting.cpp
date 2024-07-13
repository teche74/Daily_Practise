class Solution {
public:
    
    string solve(string  given, string dict){
        int size = given.size();
        string res = "";
        int ind = 0;

        for(int i = 0; i < size ; i++){
            if(dict[ind] == given[i]){
                res.push_back(dict[ind]);
                ind++;
            }
        }
        return ind == dict.size() ? res : "";
    }

    string findLongestWord(string s, vector<string>& dictionary) { 


        string res = "";
        
        for (const string& t : dictionary) {
            string temp = solve(s,t);
            if(temp == "") continue;
            if (temp.size() > res.size() || (temp.size() == res.size() && temp < res)) {
                res = temp;
            }
        }

        return res;
    }
};