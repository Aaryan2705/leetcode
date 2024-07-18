class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        
        // Manually split the string into words
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                word += s[i];
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        
        // Reverse the words
        reverse(words.begin(), words.end());
        
        // Join the words back into a single string
        string result;
        for (int i = 0; i < words.size(); ++i) {
            result += words[i];
            if (i < words.size() - 1) {
                result += " ";
            }
        }
        
        return result;
    }
};