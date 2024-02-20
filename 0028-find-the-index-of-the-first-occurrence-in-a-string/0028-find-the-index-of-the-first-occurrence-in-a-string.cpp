class Solution {
public:
    void findlps(vector<int> &lps,string s){
        int pre=0;
        int suf=1;
        while(suf < s.size()){
            if(s[pre] == s[suf]){
                lps[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre ==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                    pre=lps[pre-1];
                }
            }
        }
    }
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        findlps(lps,needle);
        int first=0,second=0;
        while(first < haystack.size() && second < needle.size()){
    //      match
            if(haystack[first] == needle[second]){
                first++,second++;
            }
    //      not-match
            else{
                if(second == 0){
                    first++;
                }
                else{
                    second = lps[second-1];
                }
            }
        }

        return (second == needle.size())? first-second : -1;
    }
};