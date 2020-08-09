#include <map>
#include <vector>

/* Definition for a binary tree node */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class CBuildTree{
	public:
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
		{
			if(preorder.empty() || inorder.empty())
			{
				return nullptr;
			}

			for(int i = 0; i < inorder.size(); i++)
			{
				m_index[inorder[i]] = i;
			}

			int len = preorder.size();
			return ReBuildTree(preorder,inorder,0,len - 1, 0, len - 1);
		}

		TreeNode* ReBuildTree(vector<int> preorder,vector<int> inorder,int preleft,int preright,int inleft,int inright)
		{
			if(preleft > preright || inleft > inright)
			{
				return nullptr;
			}

			// 前序遍历的开始即为根节点
			int rootVal = preorder[preleft];

			// 构造根节点
			TreeNode *root = new TreeNode(rootVal);

			// 找到根节点在中序遍历中的位置
			int in_root_index = m_index[rootVal];

			// 可得左子树节点数，同理也可知右子树的节点数了
			int left_subtree_size = in_root_index - inleft;
			
			// 递归的构造左子树
			root->left = ReBuildTree(preorder,inorder,preleft + 1,preleft + left_subtree_size,inleft,in_root_index - 1);
			
			// 递归的构造右子树
			root->right = ReBuildTree(preorder,inorder,preleft+left_subtree_size+1,preright,in_root_index+1,inright);
			return root;
		}

	public:
		// 存放中序遍历中值对应的下标
		map<int,int> m_index;
};