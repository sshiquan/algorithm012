// 解码方法
class Solution {
public:
    int numDecodings(string s) {
    	if(s.size() == 0 || s[0] == '0') return 0;
        vector<int> dp(s.size(), 0);
        dp[0] = 1;
        for(int i = 1; i < s.size(); i++)
        {
        	if(s[i] != '0') dp[i] = d[i-1];

        	int num = 10 * (s[i-1] - '0') + (s[i] - '0');
        	if(num >= 10 && num <= 26)
        	{
        		if(i == 1) dp[i]++;
        		else dp[i] += dp[i-2];
        	}
        }
        return dp[s.size() - 1];
    }
};