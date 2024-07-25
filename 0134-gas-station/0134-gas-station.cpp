class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int tank = 0, startIndex = 0;

        // Combine the total gas and cost calculations with the loop
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            // If tank is negative, reset the starting point
            if (tank < 0) {
                startIndex = i + 1;
                tank = 0;
            }
        }

        // If total gas is less than total cost, return -1
        return (totalGas >= totalCost) ? startIndex : -1;
    }
};