class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBrackets;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openBrackets.push(i);
            } else if (s[i] == ')') {
                int start = openBrackets.top();
                openBrackets.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' && s[i] != ')') {
                result += s[i];
            }
        }
        return result;
    }
};