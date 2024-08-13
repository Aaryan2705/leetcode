class Solution {
public:
    string reverseWords(string s) {
        // Use stringstream to split the string into words
        stringstream ss(s);
        string word;
        string result;
        
        // Add words to the result in reverse order
        while (ss >> word) {
            result = word + " " + result;
        }
        
        // Remove the trailing space and return the result
        if (!result.empty()) {
            result.pop_back();
        }
        
        return result;
    }
};

    