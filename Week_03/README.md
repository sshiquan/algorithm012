学习笔记
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