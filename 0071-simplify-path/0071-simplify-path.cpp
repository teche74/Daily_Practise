class Solution {
public:
    string simplifyPath(string path) {

        // " . " ==> Continue;
        // " . . " ==> Remove the before directory;
        // " // " ==> make it into "/"


        stack<string> s;
        
        for(int i = 0; i < path.size();) {
            while (i < path.size() && path[i] == '/') {
                i++;
            }
            string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i++];
            }
            if (temp == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else if (temp != "." && !temp.empty()) {
                s.push(temp);
            }
        }
        
        string ans;
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        return ans.empty() ? "/" : ans;
    }
};