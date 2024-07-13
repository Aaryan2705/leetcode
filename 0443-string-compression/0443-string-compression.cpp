class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 0;
        
        while (i < n) {
            int count = 1;
            while (i + 1 < n && chars[i] == chars[i + 1]) {
                i++;
                count++;
            }
            
            chars[j++] = chars[i++];
            
            if (count > 1) {
                for (char c : to_string(count)) {
                    chars[j++] = c;
                }
            }
        }
        
        return j;
    }
};