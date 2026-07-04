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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                while (prev->right != nullptr && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == nullptr) {
                    ans.push_back(curr->val);  // Visit before going left
                    prev->right = curr;        // Create thread
                    curr = curr->left;
                } else {
                    prev->right = nullptr;     // Remove thread
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};


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
    void recursiveRV(TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) {
            return;
        }
        if(level == ans.size()) {
            ans.push_back(root->val);
        }
        recursiveRV(root->right, ans, level+1);
        recursiveRV(root->left, ans, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursiveRV(root, ans, 0);
        return ans;
    }
};




// Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*, int>> q;
        map<int, int> m;
        q.push({root, 0});
        while(q.size() > 0) {
            Node* curr = q.front().first;
            int currHD = q.front().second;
            q.pop();
            m[currHD] = curr->data;
            if(curr->left != NULL) {
                q.push({curr->left, currHD-1});
            }
            if(curr->right != NULL) {
                q.push({curr->right, currHD+1});
            }
        }
        vector<int> ans;
        for(auto val : m) {
            ans.push_back(val.second);
        }
        return ans;
    }
};





/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        queue<pair<Node*, int>> q;
        map<int, int> m; 
        q.push({root, 0});
        while(!q.empty()) {
            Node* currNode = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(m.find(hd) == m.end()) {
                m[hd] = currNode->data;
            }
            if(currNode->left) {
                q.push({currNode->left, hd-1});
            }
            if(currNode->right) {
                q.push({currNode->right, hd+1});
            }
        }
        vector<int> ans;
        for(auto val : m) {
            ans.push_back(val.second);
        }
        return ans;
    }
};
