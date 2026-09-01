class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==t){
                return m;
            }
            if(nums[m]>nums[n-1]){
                if(nums[m]<t){
                    l=m+1;
            }else{
                if(nums[0]>t){
                    l=m+1;
                }else{
                    h=m-1;
                }
                     }
            }
            else{
                if(nums[m]>t){
                    h=m-1;
                }else{
                    if(nums[n-1]<t){
                        h=m-1;
                    }else{
                      l=m+1;
                    }
                }
            }
            
        }
        return -1;
    }
};