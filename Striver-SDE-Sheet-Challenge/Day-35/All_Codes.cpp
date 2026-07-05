// Max Width
class Solution {
public:
    long long int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            long long mini = q.front().second;
            long long first, last;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second - mini;
                q.pop();

                if(i == 0) first = idx;
                if(i == size - 1) last = idx;

                if(node->left)
                    q.push({node->left, 2 * idx + 1});

                if(node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};



// Print root to Leaf Path
class Solution{
public:

    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& ans){
        if(root == NULL) return;
        path.push_back(root->data);

        if(root->left == NULL && root->right == NULL){
            ans.push_back(path);
        }
        else{
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, path, ans);

        return ans;
    }
};



// Vertical Order Traversal
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> q; // Node, <vertical_distance, level>
        map<int, map<int, multiset<int>>> nodes; // vertical_distance, level, nodes
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(curr->val);
            if(curr->left) {
                q.push({curr->left, {x-1, y+1}});
            }
            if(curr->right) {
                q.push({curr->right, {x+1, y+1}});
            }
        } 
        vector<vector<int>> ans;
        for(auto p : nodes) {
            vector<int> col;
            for(auto Q : p.second) {
                col.insert(col.end(), Q.second.begin(), Q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};


// Pre, Post and Inorder in 1 Traversal
class Solution{
public:
    vector<vector<int>> treeTraversal(TreeNode* root){
        vector<int> pre, in, post;

        if(root == NULL) return {in, pre, post};

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while(!st.empty()){
            auto it = st.top();
            st.pop();

            TreeNode* node = it.first;
            int state = it.second;

            // Preorder
            if(state == 1){
                pre.push_back(node->data);

                st.push({node, 2});

                if(node->left)
                    st.push({node->left, 1});
            }

            // Inorder
            else if(state == 2){
                in.push_back(node->data);

                st.push({node, 3});

                if(node->right)
                    st.push({node->right, 1});
            }

            // Postorder
            else{
                post.push_back(node->data);
            }
        }

        return {in, pre, post};   // GFG expects {Inorder, Preorder, Postorder}
    }
};
