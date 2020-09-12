学习笔记

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


