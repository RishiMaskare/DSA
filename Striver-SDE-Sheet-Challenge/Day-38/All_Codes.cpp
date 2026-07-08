class Solution {
public:
    int maxPathDown(TreeNode* root, int& maxi) {
        if(!root) return 0;
        int left = max(0, maxPathDown(root->left, maxi));
        int right = max(0, maxPathDown(root->right, maxi));
        maxi = max(maxi, left+right+root->val);
        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
};


class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for(int i=left;i<=right;i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right) {
        if(left > right) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;
        root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size()-1);
    }
};



class Solution {
public:
    unordered_map<int, int> mp;
    int postIndex;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postIndex--]);
        int pos = mp[root->val];

        root->right = solve(inorder, postorder, pos + 1, inEnd);
        root->left = solve(inorder, postorder, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        for (int i = 0; i < n; i++) mp[inorder[i]] = i;
        postIndex = n - 1;

        return solve(inorder, postorder, 0, n - 1);
    }
};
