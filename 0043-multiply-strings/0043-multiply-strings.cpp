class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        if (num1 == "0" || num2 == "0")
            return "0";
        vector<int> ansArr(num1.length() + num2.length(), 0);
        for (int i = num1.length() - 1; i >= 0; i--) {
            for (int j =  num2.length() - 1; j >= 0; j--) {
                ansArr[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                ansArr[i + j] += ansArr[i + j + 1] / 10;
                ansArr[i + j + 1] =  ansArr[i + j + 1] % 10; 
            }
        }
        int startNum = (ansArr[0] == 0) ? 1 : 0;
        while (startNum < ansArr.size())
            ans += to_string(ansArr[startNum++]);
        return ans;
    }
};