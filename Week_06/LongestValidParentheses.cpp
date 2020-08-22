/*
32.最长有效括号
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.size(),0);
        int maxRes = 0;

        for(int i = 1; i < s.size(); i++)
        {
        	// 只有右括号结尾才可能构成有效括号
        	if(s[i] == ')')
        	{
        		if(s[i-1] == '(')
        		{
        			dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
        		}
        		else if(i - dp[i-1] > 0 && s[i-dp[i-1]-1] == '(')
        		{
        			dp[i] = dp[i-1] + (i - dp[i - 1] - 2 >= 0 ? dp[i-dp[i-1]-2] : 0) + 2;
        		}
        	}
        	maxRes = max(maxRes,dp[i]);
        }
        return maxRes;
    }
};
