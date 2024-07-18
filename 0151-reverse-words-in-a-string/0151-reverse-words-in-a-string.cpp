class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;  // Vector to store individual words
        string word;           // Temporary string to hold each word
        
        // Manually split the string into words
        for (int i = 0; i < s.size(); i++) {  // Loop through each character in the string
            if (s[i] != ' ') {  // If the character is not a space
                word = word + s[i];   // Add the character to the current word
            } else if (!word.empty()) {  // If the character is a space and the current word is not empty
                words.push_back(word);  // Add the current word to the words vector
                word.clear();           // Clear the current word to start a new one
            }
        }
        if (!word.empty()) {  // After the loop, if there's a word left (end of the string)
            words.push_back(word);  // Add the last word to the words vector
        }
        
        // Reverse the words
        reverse(words.begin(), words.end());  // Reverse the order of words in the vector
        
        // Join the words back into a single string
        string result;  // Resultant string to hold the final reversed words
        for (int i = 0; i < words.size(); i++) {  // Loop through each word in the reversed words vector
            result = result + words[i];  // Add the word to the result string
            if (i < words.size() - 1) {  // If it's not the last word
                result = result + " ";  // Add a space between words
            }
        }
        
        return result;  // Return the final reversed string
    }
};