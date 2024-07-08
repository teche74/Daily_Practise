class Solution {
public:
    int check(vector<int>pos , int dist){
        int count = 1 ;

        int prev = pos[0];

        for(int i =1; i <pos.size() ; i++){
            if( pos[i] - prev >= dist){
                prev =pos[i];
                count++;
            }
        }
        return count;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());

        int low = 0 ,  high =  pos[pos.size()-1] - pos[0] ;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(check(pos, mid) >= m){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        } 
        return high;
    }
};