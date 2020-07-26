/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    	vector<int> vecPre;
    	if(root == NULL) return vecPre;

    	vecPre.push_back(root->val);
    	PreOrder(root->left,vecPre);
    	PreOrder(root->right,vecPre);

    	return vecPre;
    }

    void PreOrder(TreeNode* root,vector<int>& vec)
    {
    	if(root == NULL) return ;

    	vec.push_back(root->val);
    	PreOrder(root->left,vec);
    	PreOrder(root->right,vec);
    }
};