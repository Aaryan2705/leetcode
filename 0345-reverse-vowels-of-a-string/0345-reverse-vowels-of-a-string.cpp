class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stack<char> vowelStack;

        // Traverse the string and push vowels onto the stack
        for (int i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                vowelStack.push(s[i]);
            }
        }

        // Traverse the string again and replace vowels with the ones from the stack
        for (int i = 0; i < s.length(); i++) {
            if (vowels.find(s[i]) != vowels.end()) {
                s[i] = vowelStack.top();
                vowelStack.pop();
            }
        }

        return s;
    }
};