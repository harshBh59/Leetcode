class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1;
        int res =-1;
        while(l<=h){
            int m=(l+h)/2;
            if(arr[m]<arr[m+1]){
                l=m+1;
            }else{
                res=m;
                h=m-1;
            }
        }
        return res;
    }
};