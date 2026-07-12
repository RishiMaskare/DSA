class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil = -1;
        while(root) {
            if(root->data == x) {
                return x;
            } else if(root->data < x) {
                root = root->right;
            } else {
                ceil = root->data;
                root = root->left;
            }
        }
        return ceil;
    }
};



class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int floor = -1;
        while(root) {
            if(root->data == k) {
                return k;
            } else if(root->data > k) {
                root = root->left;
            } else {
                floor = root->data;
                root = root->right;
            }
        }
        return floor;
    }
};





class Solution {
public:
    int ans = 0, cnt = 0;
    void inOrder(TreeNode* root, int k) {
        if(!root) return;
        inOrder(root->left, k);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        inOrder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return ans;
    }
};
