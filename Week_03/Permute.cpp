/*
46.全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > vecRes;

        backtrack(vecRes,nums,0,nums.size());

        return vecRes;
		}
    
    void backtrack(vector<vector<int> >& vecRes,vector<int> &nums,int level,int max)
    {
    	if( level >= max)
    	{
    		vecRes.emplace_back(nums);
    		return;
    	}

    	for(int i = level; i < max; i++)
    	{
    		// 保证level右边为未使用的数值
    		swap(nums[i],nums[level]);

    		backtrack(vecRes,nums,level+1,max);

    		// 恢复上一层的交换，以便在此基础上的下次处理
    		swap(nums[i],nums[level]);
    	}
    }
};