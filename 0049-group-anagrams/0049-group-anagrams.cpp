class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mp;

        for(string s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        for(auto p: mp)
        {
            ans.push_back(p.second);
        }

        return ans;
    }
};