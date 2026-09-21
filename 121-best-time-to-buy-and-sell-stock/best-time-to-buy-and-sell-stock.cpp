class Solution {
public:
    int maxProfit(vector<int>& pr) {
        int minP=pr[0];
        int maxPt=0;
        for(int i=0;i<pr.size();i++){
            minP=min(minP,pr[i]);
            int profit=pr[i]-minP;
            maxPt=max(maxPt,profit);
        }
        return maxPt;
    }
};