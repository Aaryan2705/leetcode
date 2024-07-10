class Solution {
public:
    int minOperations(vector<string>& logs) {
        //Base case
        if(logs.size() <= 0) return 0;
        int count = 0;
        //Iteration until ith index is less than equals to
        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i] == "../")
            {
                //possible when count > 0 only
                if(count > 0)
                {
                    count--;
                }
            }
            else if(logs[i] == "./")
            {
                continue;
            }
            else{
                count++;
            }
        }
        return count;
    }
};