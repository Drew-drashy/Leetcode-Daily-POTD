class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            while(n--){
                TreeNode *temp=q.front();
                maxi=max(temp->val,maxi);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            // if(maxi==-1) continue;
            ans.push_back(maxi);
        }
         return ans;
    }
   
};