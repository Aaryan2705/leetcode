class Solution {
public:
    int passThePillow(int n, int time) {
        int cycleLength = 2 * (n - 1);
        int effectiveTime = time % cycleLength;

        if (effectiveTime < n) {
            return effectiveTime + 1; // Forward direction
        } else {
            return 2 * n - effectiveTime - 1; // Backward direction
        }
    }
};
