class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size()) {
            merged += word1[i++];
            merged += word2[j++];
        }
        while (i < word1.size()) {
            merged += word1[i++];
        }
        while (j < word2.size()) {
            merged += word2[j++];
        }
        return merged;
    }
};