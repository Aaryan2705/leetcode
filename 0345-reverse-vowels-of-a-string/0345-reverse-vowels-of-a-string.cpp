class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel = { 'a', 'e', 'i', 'o', 'u', 'A' , 'E' , 'I', 'O' , 'U'};
        stack<char> collect;
        for(int i = 0 ; i < s.length(); i++){
            if(vowel.find(s[i]) != vowel.end()){
                collect.push(s[i]);
            }
        }
        for(int i = 0; i < s.length() ; i++){
            if(vowel.find(s[i]) != vowel.end()){
                s[i]=collect.top();
                collect.pop();
            }
        }
        return s;
    }
};