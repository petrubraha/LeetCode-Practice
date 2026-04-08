class Solution {
    static constexpr int MOD = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;
public:
    void applyQuery(vector<int>& nums, vector<int>& query, int n) {
        for (int i = query[0]; i <= query[1]; i += query[2]) {
            long long num = nums[i];
            nums[i] = (num * query[3]) % MOD;
        }
    }

    int xorNums(vector<int>& nums, int n) {
        int result = nums[0];
        for (int i = 1; i < n; ++i) {
            result ^= nums[i];
        }
        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        for (int i = 0; i < q; ++i) {
            applyQuery(nums, queries[i], n);
        }

        return xorNums(nums, n);
    }
};