class Solution {
public:
 struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        }
 };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        unordered_map<string,int>f;
        for(int i=0;i<n;i++){
            f[words[i]]++;
        }
    priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto i:f){
            string w=i.first;
            int freq=i.second;
    pair<int,string>curr={freq,w};
       pq.push(curr);
      if(pq.size()>k)
       pq.pop();
        }
        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            
        
        }
        
        
        reverse(res.begin(),res.end());
        return res;
    }
};