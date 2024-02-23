class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty() == false) {
                    if(s[i] == ')' && st.top() == '(') st.pop();
                    else if(s[i] == '}' && st.top() == '{') st.pop();
                    else if(s[i] == ']' && st.top() == '[') st.pop();
                    else return false;
                } else return false;
            }
        }
        if(st.empty() == true) return true;
        return false;
    }
};