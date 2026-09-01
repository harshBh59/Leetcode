class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        for(int i=0;i<=n-1;i++){
            if(nums[i]==t)
            return i;
        }
  return -1;
    }
};