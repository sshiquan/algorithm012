#include <vector>

class Solution
{
public:
	void moveZeroes(vector<int>& nums)
	{
		int indexOfNotZero = 0;
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0)
			{
				int tmp = nums[indexOfNotZero];
				nums[indexOfNotZero++] = nums[i];
				nums[i] = tmp;
			}
		}
	}
}