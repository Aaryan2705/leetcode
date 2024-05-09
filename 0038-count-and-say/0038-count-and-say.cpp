class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        } else {
            string prev = countAndSay(n-1);

            char currChar = prev[0];
            int currCount = 1;

            string ret = "";
            
            for (int i = 1; i < prev.size(); i++) {
                if (prev[i] != currChar) {
                    ret += to_string(currCount) + currChar;
                    currCount = 1;
                    currChar = prev[i];
                } else {
                    currCount++;
                }
            }

            ret += to_string(currCount) + currChar;

            return ret;
        }
    }
};