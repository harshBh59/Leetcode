class Solution {
public:
        // struct cmp{
        //     bool operator()(pair<int,int>&a,pair<int,int>&b){
        //         return a.first>b.first;
                
        //        }
               
        //     };
        vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
            unordered_map<int,int>f;
            for(int i=0;i<n;i++){
                f[nums[i]]++;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            for(auto i:f){
                int element=i.first;
                int freq=i.second;
            
            pair<int,int>curr={freq,element};
            pq.push(curr);
            if(pq.size()>k){
                pq.pop();
            }
            }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};