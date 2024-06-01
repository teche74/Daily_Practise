struct Node {
    Node* bits[2] = {nullptr, nullptr};

    void createBit(int bit, Node* node) {
        bits[bit] = node;
    }

    bool checkBit(int bit) {
        return bits[bit] != nullptr;
    }

    Node* getBit(int bit) {
        return bits[bit];
    }
};

class Solution {
    Node* root = new Node();

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->checkBit(bit)) {
                node->createBit(bit, new Node());
            }
            node = node->getBit(bit);
        }
    }

    int FindXor(int num) {
        Node* node = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->checkBit(1 - bit)) {
                maxXOR |= (1 << i);
                node = node->getBit(1 - bit);
            } else {
                node = node->getBit(bit);
            }
        }
        return maxXOR;
    }

public:
    int maximumStrongPairXor(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int res = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i; j < nums.size(); ++j) {
                int x = nums[i];
                int y = nums[j];
                if (abs(x - y) <= min(x, y)) {
                    insert(y);
                    res = max(res, FindXor(x));
                }
            }
            root = new Node();  
        }

        return res;
    }
};