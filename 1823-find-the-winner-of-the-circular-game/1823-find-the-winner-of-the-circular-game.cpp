class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0;  // Josephus problem is 0-indexed in calculation
        for (int i = 1; i <= n; ++i) {
            winner = (winner + k) % i;
        }
        return winner + 1;  // Convert back to 1-indexed
    }
};