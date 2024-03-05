class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);   
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=st.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                st.pop();
                maxL=max(maxL,i-st.top());
            }
            else
                st.push(i);
        }
        return maxL;
    }
};