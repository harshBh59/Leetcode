class Solution {
public:
    void fun(int idx,string digits,string &diary,vector<string>&res,unordered_map<char,string>&f)
   {
    //base case
    if(idx==digits.size())
    {
        res.push_back(diary);
        return;
    }
    
    
    string choice = f[digits[idx]];
    for(int j=0;j<choice.size();j++)
    {
        diary.push_back(choice[j]);
        fun(idx+1,digits,diary,res,f);
        diary.pop_back();
    }
    return;
   }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;
        
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        string diary="";
        vector<string>res;
        fun(0,digits,diary,res,f);
        return res;
    }
};