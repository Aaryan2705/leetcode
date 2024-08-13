class Solution {
public:
    string reverseWords(string s) {
        // Create a stringstream object to split the string into words
        stringstream ss(s);
        
        // Declare a variable to hold each word
        string word;
        
        // Declare a string to store the final result
        string result;
        
        // Use a while loop to extract words from the stringstream
        while (ss >> word) {
            // Prepend each word to the result string, followed by a space
            result = word + " " + result;
        }
        
        // If the result is not empty, remove the trailing space
        if (!result.empty()) {
            result.pop_back();
        }
        
        // Return the final reversed string
        return result;
    }
};
