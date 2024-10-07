class Solution {
public:
    int minLength(string s) 
    {
        string temp;
        for(auto ch:s)
        {
            if(!temp.empty() and ch == 'B' and temp.back() == 'A') 
                temp.pop_back();
            else if(!temp.empty() and ch == 'D' and temp.back() == 'C') 
                temp.pop_back();
            else temp += ch;
        }
        return temp.size();
    }
};