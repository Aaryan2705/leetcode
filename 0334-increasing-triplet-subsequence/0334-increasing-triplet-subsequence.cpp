class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int a = INT_MAX;
        int b = INT_MAX;
        for(int i=0;i<n;i++){
            int c= nums[i];
            
            if(c<=a) a=c;
            else if(c<=b) b=c;
            else return true;
        }
        return false ;
        
    }
};