class Solution {
public:
    TreeNode *fun(int prestart,int preend,int instart,int inend,vector<int>&preorder,vector<int>&inorder,map<int,int>&mp){

            if(instart>inend || prestart>preend) return NULL;
            TreeNode *root=new TreeNode (preorder[prestart]);
            int inroot=mp[root->val];
            int numsleft=inroot-instart;
            root->left=fun(prestart+1,prestart+numsleft,instart,inroot-1,preorder,inorder,mp);
            root->right=fun(prestart+numsleft+1,preend,inroot+1,inend,preorder,inorder,mp);
            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();

        map<int,int>mp;
        int k=0;
        for(int i: inorder) mp[i]=k++;
        return fun(0,n-1,0,n-1,preorder,inorder,mp);

    }
};