class TreeNode
{
  public:
    TreeNode(int val)
    {
      value = val;
      left = nullptr;
      right = nullptr;
    }

  public:
    TreeNode* left;
    TreeNode* right;
    int value;
      
};

class Solution
{
  public:
    static int maxSum(TreeNode* root)
    {
      /*Traverse to each leaf and then add from the leaf to root*/
      
      if(root == nullptr)
        return 0;
      
      int left = maxSum(root->left);
      int right = maxSum(root->right);
      return root->value + (left > right ? left : right);
  
    }
};

