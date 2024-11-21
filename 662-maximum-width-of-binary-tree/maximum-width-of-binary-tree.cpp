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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL ) return 0;
        queue<pair<TreeNode*,int>>pq;
        pq.push({root,0});
        int maxi=0;
        while(!pq.empty()){
            int n=pq.size();
            int curr;
            int last;
            int op=pq.front().second;
            for(int i=0;i<n;i++){
                TreeNode *node=pq.front().first;
                int now=pq.front().second-op;
                if(i==0) curr=now;
                if(i==n-1) last=now;
                pq.pop();
                if(node->left){
                    pq.push({node->left,(long long)2*now+1});
                }
                if(node->right){
                    pq.push({node->right,(long long)2*now+2});
                }
            }
            maxi=max(maxi,last-curr+1);
        }
        return maxi;
    }
};