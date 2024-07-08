class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>players;

        for(int i =0 ;i< n ;i++){
            players.emplace_back(i+1);
        }

        int curr=  0;

        while(players.size() >1){
            curr = (curr + k -1) % players.size();
            players.erase(players.begin() + curr);
        }

        return players[0];
    }
};