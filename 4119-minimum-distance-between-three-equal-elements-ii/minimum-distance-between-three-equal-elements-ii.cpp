class Solution {
public:
    int getDistance(int i, int k) {
        return 2 * (k - i);
    }
    
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(),
            minimum = INT_MAX;
        
        unordered_map<int, pair<int, int>> numberToIndexes;
        for (int i = 0; i < n; ++i) {
            int num = nums[i] - 1,
                pos = i + 1;
            
            auto& indexes = numberToIndexes[num];
            int oldestPos = indexes.first;
            if (oldestPos != 0) {
                int dist = getDistance(oldestPos, pos);
                if (dist == 3) {
                    return 3;
                }
                if (dist < minimum) {
                    minimum = dist;
                }
            }
            
            indexes.first = indexes.second;
            indexes.second = pos;
        }

        if (minimum == INT_MAX) {
            return -1;
        }
        return minimum;
    }
};