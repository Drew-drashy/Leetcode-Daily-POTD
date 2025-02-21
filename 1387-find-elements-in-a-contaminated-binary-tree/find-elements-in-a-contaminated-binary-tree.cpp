class FindElements {
public:
    map<int,int>mp;
    FindElements(TreeNode* root) {
        if(root==NULL) return ;
        root->val=0;
        mp[0]++;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            
            while(n--){
                TreeNode *temp=q.front();
                int val=temp->val;
                q.pop();
                if(temp->left){
                    int val2=2*val+1;
                    mp[val2]++;
                    temp->left->val=val2;
                    q.push(temp->left);
                }
                if(temp->right){
                    int val2=2*val+2;
                    mp[val2]++;
                    temp->right->val=val2;
                    q.push(temp->right);
                }
            }
        }
    }
    
    bool find(int target){
        if(mp.find(target)!=mp.end()) return true;
        return false;
    }
};