class Solution {
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(),ans=0;
        
        for(int x=-n+1;x<n;x++){
            for(int y=-n+1;y<n;y++){
                int c=0;
                
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int p=i+x,q=j+y;
                        
                        if(p>=0&&p<n&&q>=0&&q<n&&a[i][j]&&b[p][q])
                            c++;
                    }
                }
                
                ans=max(ans,c);
            }
        }
        
        return ans;
    }
};