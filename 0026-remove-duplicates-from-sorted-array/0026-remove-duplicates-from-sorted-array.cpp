class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0 ;
        }
        int j = 0 ;
         for ( int i = 0 ; i < nums.size(); i++) {
             if (nums[i] != nums[j]){
                 j++ ;
                 nums[j]= nums[i] ;
             }
         }
        return j +1 ;

    }
};

//         if (nums.empty()) {
//             return 0;
//         }

//         int j = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != nums[j]) {
//                 j++;
//                 nums[j] = nums[i];
//             }
//         }

//         return j + 1;