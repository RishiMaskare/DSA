class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL) return root;
        queue<Node*> q;
        q.push(root);
        q.push(NULL); 
        Node* prev = NULL;
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            if(curr == NULL) {
                if(q.empty()) break;
                else q.push(NULL);
            } else {
                // push curr's left and right child
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
                if(prev) {
                    prev->next = curr;
                }
            }
            prev = curr;
        }
        return root;
    }
};
