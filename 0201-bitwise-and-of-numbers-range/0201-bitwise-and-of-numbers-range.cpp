class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return right & (left-1);
    }
};