#include <vector>

class Solution {
public:
    int calculateScore(const std::vector<int>& player) {
        bool flag = false;
        int previousTwo = 0;
        int totalScore = 0;
        for (auto& it : player) {
            if (!flag) {
                totalScore += it;
            } else if (previousTwo < 2) {
                totalScore += (2 * it);
                previousTwo += 1;
            }
            if (previousTwo >= 2) flag = false;
            if (it == 10) {
                flag = true;
                previousTwo = 0;
            }
        }
        return totalScore;
    }
    
    int isWinner(const std::vector<int>& player1, const std::vector<int>& player2) {
        int score1 = calculateScore(player1);
        int score2 = calculateScore(player2);
        
        if (score1 > score2) {
            return 1;
        } else if (score2 > score1) {
            return 2;
        } else {
            return 0;
        }
    }
};
