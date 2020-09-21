class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vecRes;
        if(n <= 0) returb vecRes;
        DFS(vecRes, n, 0, 0, "");
        return vecRes;
    }

    void DFS(vector<string> &vecRes,int n,int left,int right,string strCur)
    {
    	if(left == n && right == n)
    	{
    		vecRes.push_back(strCur);
    	}

    	if(left < n)
    	{
    		DFS(vecRes,n,left+1,right,strCur+"(");
    	}
    	if(right < left)
    	{
    		DFS(vecRes,n,left,right+1,strCur+")");
    	}
    }
};