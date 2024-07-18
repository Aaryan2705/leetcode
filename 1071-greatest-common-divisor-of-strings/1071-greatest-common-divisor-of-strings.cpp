class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //checking if the str1+str2 is equal to str2+str1 or not
        //if not then gcd cannnot be find of such strings
        if(str1+str2 != str2+str1) return "";
        // else we have to find the gcd .... gcd will always start from the starting
        // the length of the gcd of the substring is equal to gcd of str1's length and str2's length
        return str1.substr(0,gcd(str1.length(),str2.length()));
    }
};