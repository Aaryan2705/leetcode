class Solution {
  public:
    string map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string digits, vector<string>& ans, int index, string current) {
        if(index == digits.length()) {
            ans.push_back(current);
            return;
        }
        string s = map[digits[index]-'0'];
        for(int i = 0; i < s.length(); i++) {
            helper(digits, ans, index+1, current+s[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length() == 0) return ans;

        helper(digits, ans, 0, "");
        return ans; 
    }
};