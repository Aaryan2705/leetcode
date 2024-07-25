class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, startIndex = 0;

        // Step 1: Calculate total gas and total cost
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        // Step 2: If total gas is less than total cost, return -1
        if (totalGas < totalCost) {
            return -1;
        }

        // Step 3: Find the starting point
        for (int i = 0; i < gas.size(); ++i) {
            tank += gas[i] - cost[i];
            // If tank is negative, reset the starting point
            if (tank < 0) {
                startIndex = i + 1;
                tank = 0;
            }
        }

        return startIndex;
    }
};