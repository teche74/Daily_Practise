// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int index = 0;

        for(long long i  = n ; i >= 1 ; i/=2){
            while(index + i <= n && !isBadVersion(index+ i)) index+=i;
        }

        return index+1;
    }
};