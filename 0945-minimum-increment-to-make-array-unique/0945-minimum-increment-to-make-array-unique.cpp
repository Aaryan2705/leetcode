class Solution {
public:
    static int minIncrementForUnique(vector<int>& nums) {
        int freq[200001]={0}, x0=1e5, n=nums.size();
        for(int x: nums){
            freq[x]++;
            x0=min(x0, x);
        }
        int cnt=0, inc=0;
        for(int x=x0; cnt<n; x++){
            int f=freq[x];
            cnt+=(f!=0);
            if (f<=1) continue;
            freq[x+1]+=(f-1);
            inc+=(f-1);
        }
        
        return inc;
    }
};