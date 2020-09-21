class Solution {
public:
    int longestValidParentheses(string s) {
    	if(s.size() == 0) return 0;

    	vector<int> dp(s.size(), 0);
    	int maxCount = 0;
    	for(int i = 1; i < s.size(); i++)
    	{
    		// 以右括号结束才能组成有效括号串
    		if(s[i] == ')')
    		{
    			if(s[i-1] == '(')
    			{
    				dp[i] = (i-2 >= 0 ? dp[i-2] : 0) + 2;
    			}
    			else if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(')
    			{
    				dp[i] = dp[i-1] + (i-dp[i-1]-2 >= 0 ? dp[i-dp[i-1]-2] : 0) + 2;
    			}
    		}
    		maxCount = max(maxCount,dp[i]);
    	}
    	return maxCount;
    }
};