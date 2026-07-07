class Solution {
  public:
    bool isLeaf(Node* root) {
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        return false;
    }
    void leftboundaryTraversal(Node* curr, vector<int>& ans) {
        while(curr) {
            if(!isLeaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void leafNodes(Node* root, vector<int>& ans) {
        if(!root) return;
        if(isLeaf(root)) ans.push_back(root->data);
        leafNodes(root->left, ans);
        leafNodes(root->right, ans);
    }
    void rightboundaryTraversal(Node* curr,  vector<int>& ans) {
        stack<int> st;
        while(curr) {
            if(!isLeaf(curr)) st.push(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        if(isLeaf(root)) return ans;
        leftboundaryTraversal(root->left, ans);
        leafNodes(root, ans);
        rightboundaryTraversal(root->right, ans);
        return ans;
    }
};



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);
        if(leftLCA && rightLCA) {
            return root;
        } else if(leftLCA != NULL) {
            return leftLCA;
        } else{
            return rightLCA;
        }
    }
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return isLeftSame && isRightSame && p->val == q->val;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        if(root == NULL) return ans;
        while(!q.empty()) {
            int size = q.size();
            vector<int> row(size);
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = ltr ? i : size-i-1;
                row[index] = node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            ltr = !ltr;
            ans.push_back(row);
        }
        return ans;
    }
};
