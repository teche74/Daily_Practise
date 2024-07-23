class Solution {
public:
    string decodeString(string s) {
        stack<int>count;
        stack<string> strings;
        string res = "";

        int index= 0, size = s.size();

        while(index < size){
            if(isdigit(s[index])){
                int cnt  = 0;
                while(isdigit(s[index])){
                    cnt = cnt * 10 + (s[index] - '0');
                    index++;
                }
                count.push(cnt);
            }
            else if(s[index] == '['){
                strings.push(res);
                res = "";
                index++;
            }
            else if(s[index] == ']'){
                string temp = strings.top();
                strings.pop(); 
                while(count.top()--){
                    temp +=res;
                }
                count.pop();
                res = temp;
                index++;
            }
            else{
                res += s[index];
                index++;
            }
        }

        return res;
    }
};