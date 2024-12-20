/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode *L,TreeNode *R, int level){
        if(L==NULL || R==NULL) return;
        if(level%2==0){
            int temp=L->val;
            L->val=R->val;
            R->val=temp;
        }
        fun(L->left,R->right,level+1);
        fun(L->right,R->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        fun(root->left,root->right,0);
        return root;
    }
};