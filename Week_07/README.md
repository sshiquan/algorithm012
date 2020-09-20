学习笔记

字典树(Trie):又称单词查找树或键树。典型应用于统计和排序大量字符串，经常被搜索系统用于文本词频统计。
优点：最大限度减少无谓字符串得比较，查询效率比哈希表高
基本性质：
1.节点本身不存完整单词
2.从根节点到某一节点，路径上经过得字符连接起来，为该节点对应得字符串
3.每个节点的所有子节点路径代表的字符都不相同(每一条路径构成的单词都不同)

核心思想：Trie树的核心思想是空间换时间。利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的

以26字母为例建树：
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
       for(char ch : word)
       {
           if(node->next[ch - 'a'] == NULL)
           {
                node->next[ch - 'a'] = new Trie();
           }
           node = node->next[ch - 'a'];
       }
       node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for(auto ch : word)
        {
            node = node->next[ch - 'a'];
            if(node == NULL)
            {
                return false;
            }
        }
        return node->isEnd ;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto ch : prefix)
        {
            node = node->next[ch - 'a'];
            if(node == NULL) return false;
        }
        return true;
    }
}; 

--------------------------------

剪枝 & 搜索：

双向搜索：起点和终点分别做广度优先，到中间相遇，这样更快

启发式搜索：利用优先级队列



--------------------------------

二叉搜索树：
1.左子树上所有结点的值均小于根结点值
2.右子树上所有结点的值均大于根结点值
3.以此类推，左、右子树也分别为二叉搜索树
中序遍历：升序

AVL树：
平衡因子：左子树的高度减去右子树的高度(或者相反) ={-1，0，1}
通过旋转操作来进行平衡(四种：左旋、右旋、左右旋、右左旋)
缺点：结点需要存储额外信息、且调整次数频繁


红黑树：
一种近似平衡的二叉搜索树，任何一个结点的左右子树高度差小于2倍。满足如下条件：
1.每个结点要么红色，要么黑色
2.根结点是黑色
3.每个叶节点是黑色
4.不能有相邻的两个红色结点
5.从任意结点到其他每个叶子的所有路径都包含相同数目的黑色结点




