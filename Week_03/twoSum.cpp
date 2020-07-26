class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> vecResult;
    	map<int,int> mapT;
    	for(int i = 0; i < nums.size(); i++)
    	{
    		if(mapT.find(target - nums[i]) != mapT.end())
    		{
    			vecResult.push_back(mapT[target-nums[i]]);
    			vecResult.push_back(i);
    		}
    		else
    		{
    			mapT[nums[i]] = i;
    		}
    	}

    	return vecResult;
    }
};