毕业总结：

数据结构：
一维：
数组：插入、删除O(N)
链表：插入、删除O(1)、查找O(N)
栈stack：特性：先进后出
队列queue：先进先出
双端队列deque：头尾都可进出元素
集合set：集合内元素不重复


二维：
树tree：树的遍历(前中后序)
图graph：
二叉搜索树：

关于算法：
计算机语言本来就是人类发明，只会笨笨的if-else,for,while loop，Recursion,所以多数算法题都可以在20行内解决，关键在于寻找重复子问题

常用：递归、动态规划、二分查找


递归的代码模板：
void recursion(level,param1,param2,...)
	# 1.终止条件
	if level > MAX_LEVEL:
	return
	# 2.当前层处理逻辑
	process(level,param...)
	# 3.进入下一层
	recursion(level+1,p1...)
	# 4.清理当前层需要清理的数据
	
思维要点：
1.摒弃人肉递归
2.要寻找最近重复子问题
3.学会运用数学归纳法的推理(类似：放鞭炮只要点燃第一颗即可知后面相邻的一颗必定回爆炸)



动态规划：
   分治 + 最优子结构

关键点：
	动态规划和递归或者分治没有根本上的区别(关键看有无最优子结构)
	共性：找到重复子问题
	差异性：最优子结构 、 中间可以淘汰次优解
	
动态规划的关键思想：
1.最优子结构 opt[n] = bestl_of(opt[n-1],opt[n-2]...)
2.存储中间状态 opt[i] (该步骤在实际解题中最难最重要)
3.递推公式(状态转移方程或者叫DP方程)

斐波那契数列：傻递归->中间状态缓存->递推解法的优化过程！

64.最小路径和
该题和八皇后问题思路相似但又不同，八皇后问题需要一直向下递归直至发现最后无法满足放置条件时才结束，此时需要回溯到上一行的下一个位置继续尝试求解。 而最小路径和问题，每一步即可得到最优解，因此可直接递推，而且率先经过的路径总会位于即将访问路径的左上方，因此可直接修改原二维数组，不用开辟新的空间，在O(M*N)时间复杂度，O(1)空间复杂度下即可完成。




异或：相同为0，不同为1

x ^ 0 = x

x ^ 1s = ~x  // 1s = ~0

x ^ (~x) = 1s

x ^ x = 0

常用操作：
1.将x最右边n位清零: x&(1<<n)
2.获取x的第n位值(0或1): (x>>n)&1 
3.获取x的第n位的幂值：x&(1<<n)
4.仅将第n位置为1: x|(1<<n)
5.仅将第n位置为0: x&(~(1<<n))
6.将x最高位至第n位(含)清零:x&((1<<n)-1)

应用:
判断奇偶：
x%2 == 1 => x&1 == 1
x%2 == 0 => x&1 == 0

x/2 => x>>1 ==> 二分查找中:mid=(left+right)/2 => mid=(left+right)>>1

清零最低位的1：x = x&(x-1)
得到最低位的1：x&-x
x&~x=>0



--------------------------------------------------
冒泡排序 ： O(n^2)  O(1) 稳定
void BubbleSort(vector<int> arr)
{
	for(int i = 0; i < arr.size() - 1; i++)
	{
		for(int j = 0; j < arr.size() - i - 1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				int tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

选择排序：O(n^2) O(1) 不稳定
void SelectSort(vector<int> arr)
{
    int minIndex = 0;
    for(int i = 0 ;i < arr.size(); i++)
    {
        minIndex = i;
        for(int j = i+1; j < arr.size(); j++)
        {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        if(minIndex != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = arr[i];
        }
    }
}

插入排序：O(n^2) O(1) 稳定
void InsertSort(vector<int> arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		int base = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > base)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = base;
	}
}

快速排序：O(logn) O(1) 稳定
int Partition(vector<int> arr,int low,int high)
{
	int base = arr[low];
	
	while(low < high)
	{
		while(low < high && arr[high] >= base)
		{
			high--;
		}
		// 交换low和high位置的值
		int tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
		while(low < high && arr[low] <= base)
		{
			low++;
		}
		tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
	}
	arr[low] = base;
	return low;
}

void QuickSort(vector<int> arr,int low,int high)
{
	if(low < high)
	{
		int nIndex = Partition(arr,low,high);
		QuickSort(arr,low,nIndex-1);
		QuickSort(arr,nIndex+1,high);
	}
}


整体收获：
1.经过算法训练营，逐渐养成自主刷题的习惯，虽然刷的没那么频繁，但是我认为走的慢总比原地不动强。
2.训练营中的超哥总结的递归等代码模板很受用，以前真心没有关注过这个也能形成模板类的代码。
3.面对动态规划、分治一类问题，还是有点生疏，以后还要自己督促自己多刷一些相关题目，另外超哥的视频也要回看几遍巩固加深。
4.另外还有一些笔记在个人笔记本上，有空再补充到git上来。