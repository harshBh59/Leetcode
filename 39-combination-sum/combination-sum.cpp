class Solution {
public:
 void fun(vector<int>&a,int n,int idx,vector<int>&diary,int sum,vector<vector<int>>&res,int target){
    if(idx==n){
        if(sum==target)
        res.push_back(diary);
        return;
    }
    fun(a,n,idx+1,diary,sum,res,target);
    if(a[idx]+sum<=target){
        diary.push_back(a[idx]);
        sum+=a[idx];
    
    fun(a,n,idx,diary,sum, res,target);
    diary.pop_back();
    sum-=a[idx];
    return;
    }
 }
    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        int n=a.size();
        int sum=0;
        vector<int>diary;
        vector<vector<int>>res;
        fun(a,n,0,diary,0,res,target);
        return res;
    }
};