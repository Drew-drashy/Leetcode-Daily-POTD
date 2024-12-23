// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int minimumOperations(TreeNode* root) {
//         if(root==NULL) return 0;
//         queue<TreeNode*>q;
//         q.push(root);
//         int cnt=0;
//         while(!q.empty()){
//             int n=q.size();
//             vector<int>arr;
            
//             while(n--){
//                 TreeNode *temp=q.front();
//                 q.pop();
//                 arr.push_back(temp->val);
//                 if(temp->left){
//                     q.push(temp->left);
//                 }
//                 if(temp->right){
//                     q.push(temp->right);
//                 }
//             }
//             vector<int>sp=arr;
//             sort(sp.begin(),sp.end());
//             map<int,int>mp;
//             for(int i=0;i<sp.size();i++){
//                 mp[arr[i]]=i;
//             }
//             for(int i=0;i<sp.size();i++){
//                 while(arr[i]!=sp[i]){
//                     int curr=mp[sp[i]];
//                     cnt++;
//                     swap(arr[i],arr[curr]);
//                 }
//             }

//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root)
            return 0;

        queue<TreeNode*> q;
        q.push(root);
        int operations = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            vector<int> sort_level = level;
            sort(sort_level.begin(), sort_level.end());
            unordered_map<int, int> mp;

            for (int i = 0; i < level.size(); ++i) {
                mp[level[i]] = i;
            }

            for (int i = 0; i < level.size(); ++i) {
                while (level[i] != sort_level[i]) {
                    ++operations;
                    int cur = mp[sort_level[i]];
                    mp[level[i]] = cur;
                    swap(level[i], level[cur]);
                }
            }
        }

        return operations;
    }
};