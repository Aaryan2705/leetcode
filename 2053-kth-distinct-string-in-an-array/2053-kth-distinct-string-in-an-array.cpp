class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        for(int i=0;i<arr.size();i++){
            int count = 0 ;
            for(int j = 0 ; j < arr.size();j++){
                if(arr[i]==arr[j]){
                    count++;
                }
            }
            if(count==1){
                k--;
                if(k==0){
                    return arr[i];
                }
            }            
        }
        return "";
    }
};