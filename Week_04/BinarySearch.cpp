#include <vector>

/*
33. 搜索旋转排序数组
示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
        {
        	return -1;
        }

        int left = 0, right = nums.size() - 1;

        while(left <= right)
        {
        	int mid = (left + right) / 2;

        	if( nums[mid] == target) return mid;

        	// 说明该段是升序的
        	if(nums[0] <= nums[mid])
        	{
        		if( target >= nums[0] && target <nums[mid] )
        		{
        			right = mid - 1;
        		}
        		else{
        			left = mid + 1;
        		}
        	}
        	else
        	{
        		if(target > nums[mid] && target <= nums[nums.size() - 1])
        		{
        			left = mid + 1;
        		}
        		else{
        			right = mid - 1;
        		}
        	}
        }
        return -1;
    }
};