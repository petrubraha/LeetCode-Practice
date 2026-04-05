class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int countDirections[4] = {0, 0, 0, 0};
        for (int i = 0; i < n; ++i) {
            switch (moves[i]) {
                case 'U':
                    ++countDirections[0];
                    break;
                case 'D':
                    ++countDirections[1];
                    break;
                case 'L':
                    ++countDirections[2];
                    break;
                case 'R':
                    ++countDirections[3];
                    break;
                default:
                    break;
            }
        }

        return countDirections[0] == countDirections[1]
            && countDirections[2] == countDirections[3];        
    }
};