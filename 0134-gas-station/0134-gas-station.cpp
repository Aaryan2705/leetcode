class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int tank = 0, startIndex = 0;

        for (int i = 0; i < n; ++i) {
            int netGas = gas[i] - cost[i];
            totalGas += gas[i];
            totalCost += cost[i];
            tank += netGas;

            if (tank < 0) {
                startIndex = i + 1;
                tank = 0;
            }
        }

        return (totalGas >= totalCost) ? startIndex : -1;
    }
};