class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> vecInorder;
    	if(root == NULL) return vecInorder;

    	Inorder(root->left,vecInorder);
    	vecInorder.push_back(root->val);
    	Inorder(root->right,vecInorder);

    	return vecInorder;
    }

    void Inorder(TreeNode* root,vector<int> &vec)
    {
    	if(root == NULL) return;

    	if(root->left != NULL)
    	{
    		Inorder(root->left,vec);
    	}
    	vec.push_back(root->val);
    	if(root->right != NULL)
    	{
    		Inorder(root->right,vec);
    	}
    }
};