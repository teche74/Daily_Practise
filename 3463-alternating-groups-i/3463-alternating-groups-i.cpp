class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int prev , curr, far;
        int count  = 0,size = colors.size();
        for(int i = 0 ;i < size ; i++){
            prev = i-1 == -1 ? size-1 : i-1 ;
            curr = i;
            far  = i+1 == size ? 0 : i+1;


            if(colors[curr] != colors[prev] && colors[curr] != colors[far]){
                count++;
            } 
        } 
        return count;
    }
};