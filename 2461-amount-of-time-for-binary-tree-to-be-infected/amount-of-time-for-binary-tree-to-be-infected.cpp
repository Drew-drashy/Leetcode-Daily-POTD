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
    // you assume the correct approach to solve this
    // create the tree to graph 
    // by using bfs you can count the time minimum..
    void fun(TreeNode *root, unordered_map<int,vector<int>>&adj
){
    if(root==NULL) return ;
    if(root->left){
        adj[root->left->val].push_back(root->val);
        adj[root->val].push_back(root->left->val);
    }
    if(root->right){
        adj[root->right->val].push_back(root->val);
        adj[root->val].push_back(root->right->val);
    }
    fun(root->left,adj);
    fun(root->right,adj);
}
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        fun(root,adj);
        queue<int>q;
        unordered_set<int>vis;
        int min=-1;
        q.push(start);
        // vis.insert(currnode);
        vis.insert(start);
        while(!q.empty()){
            int n=q.size();
            min+=1;
            for(int i=0;i<n;i++){
                
                int currnode=q.front();
                q.pop();
                
                for(auto it : adj[currnode]){
                    if(!vis.count(it)){
                        vis.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        return min;
    }
};