class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int>map;

        for(auto t : emails){
            size_t atPos = t.find('@');

            if (atPos != string::npos) {
                string local = t.substr(0, atPos);
                string domain = t.substr(atPos + 1);

                string new_email ="";

                for (char c : local) {
                    if (c == '+') {
                        break;  
                    }
                    if (c != '.') {
                        new_email += c; 
                    }
                }

                map[new_email + "@" + domain]++;
            }
        }

        return map.size();
    }
};