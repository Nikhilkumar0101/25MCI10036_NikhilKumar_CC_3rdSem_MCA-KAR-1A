class Solution {
public:
    vector<vector<int>> ans;

    void solve(TreeNode *root, int targetSum, vector<int> temp){
        if(root==nullptr) return;
        targetSum=targetSum-(root->val);
        temp.push_back(root->val);
        if(targetSum==0 && root->left==nullptr && root->right==nullptr){
            ans.push_back(temp);
            return;
        }
        solve(root->left, targetSum, temp);
        solve(root->right, targetSum, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,targetSum,temp);
        return ans;
    }
};