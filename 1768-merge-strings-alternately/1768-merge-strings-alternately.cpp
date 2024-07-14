class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0;
        int j = 0;
        while (i<word1.size() && j<word2.size()){
            merged = merged + word1[i++];
            merged = merged + word2[j++];
        }
        while (i < word1.size()){
            merged = merged + word1[i++];
        }
        while (j < word2.size()){
            merged = merged + word2[j++];
        }
        return merged;
    }
};