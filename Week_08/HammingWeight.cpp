/*
191.位1的个数
 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int nCount = 0;
        while(n)
        {
        	n = n & (n-1);
        	nCount++;
        }
        return nCount;
    }
};