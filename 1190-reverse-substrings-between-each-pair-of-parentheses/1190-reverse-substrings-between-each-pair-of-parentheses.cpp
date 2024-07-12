class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == ')') {
                string temp = "";
                // Pop until we find an opening parenthesis '('
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                st.pop();  // Remove the '(' from the stack

                // Push the reversed substring back to the stack
                for (int j = 0; j < temp.length(); j++) {
                    st.push(temp[j]);
                }
            } else {
                st.push(c);
            }
        }

        // Build the final result
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        // Reverse the result since it is constructed in reverse order
        reverse(result.begin(), result.end());

        return result;
    }
};