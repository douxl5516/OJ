/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void reverse(TreeNode* node,int &sum){
        if (!node){
            return;
        }
        reverse(node->right,sum);
        sum+=node->val;
        node->val=sum;
        reverse(node->left,sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        reverse(root,sum);
        return root;
    }
};