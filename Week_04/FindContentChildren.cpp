#include <vector>

// 力扣 455.分发饼干
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
    	int nCount = 0;

    	std::sort(g.begin(),g.end());
    	std::sort(s.begin(),s.end());

    	int i = 0, j = 0;
    	while(i < g.size() && j < s.size())
    	{
    		// 该对值满足胃口值
    		if(g[i++] <= s[j++])
    		{
    			nCount++;
    		}
    		else
    		{
    			// 胃口值此时无需步进
    			i--;
    		}
    	}
    }
};
