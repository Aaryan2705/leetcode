class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;

        // Calculate the total gas and total cost
        for (int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        // If the total gas is less than the total cost, it's impossible to complete the circuit
        if (totalCost > totalGas) {
            return -1;
        }

        // Try to find the starting gas station
        for (int i = 0; i < n; ++i) {
            currentGas += gas[i] - cost[i];
            // If currentGas is negative, reset it and set the next station as the starting point
            if (currentGas < 0) {
                startIndex = i + 1;
                currentGas = 0;
            }
        }

        return startIndex;
    }
};