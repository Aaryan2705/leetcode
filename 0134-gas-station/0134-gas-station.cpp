class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(); // Store the number of gas stations
        int totalGas = 0, totalCost = 0, currentGas = 0, startIndex = 0;

        // Calculate the total amount of gas and the total cost needed
        for (int i = 0; i < n; i++) {
            totalGas += gas[i]; // Add the gas available at station i to totalGas
            totalCost += cost[i]; // Add the cost to travel from station i to i+1 to totalCost
        }

        // If the total gas available is less than the total cost required, the circuit cannot be completed
        if (totalCost > totalGas) {
            return -1; // Return -1 to indicate it's impossible to complete the circuit
        }

        // Try to find the starting gas station from where the circuit can be completed
        for (int i = 0; i < n; i++) {
            currentGas += gas[i] - cost[i]; // Update currentGas by adding gas at station i and subtracting the cost to reach the next station
            // If currentGas is negative, it means starting from startIndex to this station i is not possible
            if (currentGas < 0) {
                startIndex = i + 1; // Set the next station (i + 1) as the new starting point
                currentGas = 0; // Reset currentGas to 0
            }
        }

        return startIndex; // Return the starting gas station index from where the circuit can be completed
    }
};
