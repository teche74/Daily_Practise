struct RMQ {
    int n, LOG;
    vector<int> lg;
    vector<vector<int>> st; 
    const vector<int>* A;
    bool wantMax; 

    RMQ() {}
    RMQ(const vector<int>& a, bool isMax) { build(a, isMax); }

    void build(const vector<int>& a, bool isMax) {
        A = &a;
        wantMax = isMax;
        n = a.size();
        LOG = 1;
        while ((1<<LOG) <= n) ++LOG;
        lg.assign(n+1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i>>1] + 1;
        st.assign(LOG, vector<int>(n));
        for (int i = 0; i < n; ++i) st[0][i] = i;
        for (int k = 1; k < LOG; ++k) {
            int len = 1 << k;
            int half = len >> 1;
            for (int i = 0; i + len - 1 < n; ++i) {
                int x = st[k-1][i];
                int y = st[k-1][i + half];
                if (wantMax) {
                    if ((*A)[x] >= (*A)[y]) st[k][i] = x; else st[k][i] = y;
                } else {
                    if ((*A)[x] <= (*A)[y]) st[k][i] = x; else st[k][i] = y;
                }
            }
        }
    }

    int queryIdx(int L, int R) const {
        int len = R - L + 1;
        int k = lg[len];
        int x = st[k][L];
        int y = st[k][R - (1<<k) + 1];
        if (wantMax) {
            return ((*A)[x] >= (*A)[y]) ? x : y;
        } else {
            return ((*A)[x] <= (*A)[y]) ? x : y;
        }
    }
};

using T = tuple<long long,int,int,int,int>;

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> velnorquis = nums;

        if (n == 0) return 0;
        RMQ rmqMin(nums, false), rmqMax(nums, true);

        priority_queue<T> pq;
        unordered_set<unsigned long long> seen;
        seen.reserve(1<<16);

        auto pack = [&](int a, int b)->unsigned long long {
            return ( (unsigned long long)(unsigned)a << 32 ) | (unsigned long long)(unsigned)b;
        };

        int mi = rmqMin.queryIdx(0, n-1);
        int ma = rmqMax.queryIdx(0, n-1);
        long long initD = (long long)nums[ma] - nums[mi];
        if (initD > 0) {
            pq.emplace(initD, 0, mi, ma, n-1);
            seen.insert(pack(0, n-1));
        }

        long long ans = 0;
        while (k > 0 && !pq.empty()) {
            auto [d, L, i, j, R] = pq.top(); pq.pop();
            int li = min(i,j), ri = max(i,j);
            long long cnt = (long long)(li - L + 1) * (long long)(R - ri + 1);
            if (cnt >= k) {
                ans += (long long)k * d;
                k = 0;
                break;
            }
            ans += cnt * d;
            k -= cnt;

            if (L <= ri - 1) {
                int a = L, b = ri - 1;
                unsigned long long key = pack(a,b);
                if (!seen.count(key)) {
                    seen.insert(key);
                    int mIdx = rmqMin.queryIdx(a,b);
                    int MIdx = rmqMax.queryIdx(a,b);
                    long long D2 = (long long)nums[MIdx] - nums[mIdx];
                    if (D2 > 0) pq.emplace(D2, a, mIdx, MIdx, b);
                }
            }
            if (li + 1 <= R) {
                int a = li + 1, b = R;
                unsigned long long key = pack(a,b);
                if (!seen.count(key)) {
                    seen.insert(key);
                    int mIdx = rmqMin.queryIdx(a,b);
                    int MIdx = rmqMax.queryIdx(a,b);
                    long long D2 = (long long)nums[MIdx] - nums[mIdx];
                    if (D2 > 0) pq.emplace(D2, a, mIdx, MIdx, b);
                }
            }
        }
        return ans;
    }
};
