class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0); // Array to store the frequency of each letter

        // Count the frequency of each character in the word
        for (int i = 0; i < word.size(); i++) {
            cnt[word[i] - 'a']++;
        }

        // Sort the frequency array in descending order
        sort(cnt.rbegin(), cnt.rend());

        int ans = 0;

        // Calculate the minimum pushes required
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) break; // Stop if there are no more letters
            ans += (i / 8 + 1) * cnt[i];
        }

        return ans;
    }
};