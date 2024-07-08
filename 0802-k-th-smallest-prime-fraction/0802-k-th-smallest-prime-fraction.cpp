class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto cmp = [&arr](const pair<int, int>& a, const pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);

        for (int i = 1; i < arr.size(); ++i) {
            minHeap.emplace(0, i);
        }

        for (int i = 1; i < k; ++i) {
            auto [num, den] = minHeap.top();
            minHeap.pop();

            if (num + 1 < den) {
                minHeap.emplace(num + 1, den);
            }
        }

        return {arr[minHeap.top().first], arr[minHeap.top().second]};
    }
};