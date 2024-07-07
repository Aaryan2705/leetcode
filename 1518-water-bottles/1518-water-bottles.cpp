class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = numBottles; // Initially, we can drink all full bottles
        int emptyBottles = numBottles;
        
        while (emptyBottles >= numExchange) {
            int newFullBottles = emptyBottles / numExchange;
            totalDrank += newFullBottles;
            emptyBottles = emptyBottles % numExchange + newFullBottles;
        }
        
        return totalDrank;
    }
};