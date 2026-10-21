class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if(is_sorted(s.begin(), s.end())){
            return 0;
        }
        if(s.size() == 2){
            return -1;
        }
        char maxi = 'a';
        char mini = 'z';
        for(char ch : s){
            if(ch > maxi){
                maxi = ch;
            }
            if(ch < mini){
                mini = ch;
            }
        }
        if(s[0] == mini || s[n-1] == maxi){
            return 1;
        }
        else if(s[0] == maxi && s[n-1] == mini){
            for(int i =1; i<n-1; i++){
                if(s[i] == mini || s[i] == maxi){
                    return 2;
                }
            }
            return 3;
        }
        return 2;
    }
};