class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       if (sum > 9 * num) return "";

        string ans = "";

        while (num--) {
            if (sum >= 9) {
                ans += '9';
                sum -= 9;
            } else {
                ans += char('0' + sum);
                sum = 0;
            }
        }

        return ans;  
    }
};