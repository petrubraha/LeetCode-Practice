class Solution {
public:
    int getDistance(int i, int j, int k) {
        return 2 * (k - i);
        // return abs(i - j) + abs(j - k) + abs (i - k);
    }
    
    int minimumDistance(vector<int>& nums) {
        int n = nums.size(),
            minimum = 199,
            firstOccurence[100],
            secondOccurence[100];

        for (int i = 0; i < n; ++i) {
            int num = nums[i] - 1,
                pos = i + 1;
            if (firstOccurence[num] != 0) {
                int dist = getDistance(firstOccurence[num], secondOccurence[num], pos);
                if (dist == 3) {
                    return 3;
                }
                if (dist < minimum) {
                    minimum = dist;
                }
            }
            
            firstOccurence[num] = secondOccurence[num];
            secondOccurence[num] = pos;
        }

        if (minimum == 199) {
            return -1;
        }
        return minimum;
    }
};