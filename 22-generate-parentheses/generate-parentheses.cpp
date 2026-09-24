class Solution {
public:
   void fun(int l,int h,int n, string &s,vector<string>&res)
    {
        if(l==n&&h==n){
            res.push_back(s);
            return ;
        }
        if(l<n){
            s.push_back('(');
            fun(l+1,h,n,s,res);
                s.pop_back();
            
        }
        if(h<l){
            s.push_back(')');
            fun(l,h+1,n,s,res);
                s.pop_back();
            
        }
    }
         vector<string> generateParenthesis(int n){
        vector<string>res;
        string s="";
        fun(0,0,n,s,res);
        return res;
        
         
    }
};