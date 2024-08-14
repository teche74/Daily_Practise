class Solution {
public:
    int numTrees(int n) {
        int save[n+1];
        memset(save , 0, sizeof(save));

        save[0] =1 , save[1] = 1;

        for(int total =2 ; total <= n ; total++){
            for(int left = 0; left < total ; left++){
                int right = total - left  - 1;

                save[total] += save[left] * save[right]; 
            }
        }

        return save[n];
    }
};