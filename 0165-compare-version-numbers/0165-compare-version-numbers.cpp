class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i =0 ,  j = 0 , m = v1.size() , n = v2.size();

        while(i < m || j < n){

            if(v1[i] == '.'){
                i++;
            }
            if(v2[j] == '.'){
                j++;
            }
            
            string val1 = "";

            while( i < m && isdigit(v1[i])){
                val1.push_back(v1[i]);
                i++;
            }

            string val2 ="";

            while(j < n && isdigit(v2[j])){
                val2.push_back(v2[j]);
                j++;
            }

            int x = val1.empty() ? 0 : stoi(val1) , y = val2.empty() ? 0 : stoi(val2);
            // cout<<x<<y<<endl;

            if(x > y) return 1;
            if(x < y) return -1;
        } 
        return 0;
    }
};