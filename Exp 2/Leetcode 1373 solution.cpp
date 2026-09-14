class info{
public:
    bool isBST;
    int mx;
    int mn;
    int sum;

    info(bool isBST, int mx, int mn, int sum){
        this->isBST=isBST;
        this->mx=mx;
        this->mn=mn;
        this->sum=sum;
    }
};

class Solution {
public:
    int maxsum=0;
    int maxSumBST(TreeNode* root) {
        info ans=bst(root);
        return maxsum;
    }
    info bst(TreeNode* root){
        if(root==nullptr){
            return info(true,INT_MIN,INT_MAX,0);
        }
        info left=bst(root->left);
        info right=bst(root->right);

        if(left.isBST && right.isBST && left.mx<root->val &&right.mn>root->val){
            int t_sum=left.sum+right.sum+root->val;
            maxsum=max(maxsum,t_sum);
            int mx=max(root->val,right.mx);
            int mn=min(root->val,left.mn);
            return info(true,mx,mn,t_sum);  
        }
        return info(false,0,0,0);
    }
};