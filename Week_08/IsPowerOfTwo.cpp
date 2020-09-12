/*
231.2的幂
解题思路：凡是2的幂，其二进制表示中只有一位1
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
    	return (n > 0) && ((n & (n-1)) == 0)
    }
};