// Inorder Traversal
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root) return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderSequence;
        inorder(root, inorderSequence);
        return inorderSequence;
    }
};


// Preorder Traversal
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& arr) {
        if(!root) return;

        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderSequence;
        preorder(root, preorderSequence);
        return preorderSequence;
    }
};


// Postorder Traversal
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& arr) {
        if(!root) return;

        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderSequence;
        postorder(root, postorderSequence);
        return postorderSequence;
    }
};


// Morris Inorder Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while(curr != nullptr) {
            if(curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                // find inorder predecessor
                while(pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }
                if(pred->right == nullptr) {
                    // create a thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove thread
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
