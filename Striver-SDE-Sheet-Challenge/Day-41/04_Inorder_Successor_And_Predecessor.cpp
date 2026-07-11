class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node* Root = root;
        
        vector<Node*> ans = {NULL, NULL};
        Node* IP = NULL; // just smaller
        
        while(root) {
            if(root->data >= key) {
                root = root->left;
            } else {
                IP = root;
                root = root->right;
            }
        }
        
        Node* IS = NULL; // just greater
        root = Root;
        while(root) {
            if(root->data <= key) {
                root = root->right;
            } else {
                IS = root;
                root = root->left;
            }
        }
        if(IP) {
            ans[0] = IP;
        }
        if(IS) {
            ans[1] = IS;
        }
        return ans;
    }
};
