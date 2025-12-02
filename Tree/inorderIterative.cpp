#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> stack;
    TreeNode* curr = root;
    while (curr || !stack.empty()) {
        if (curr) {
            stack.push(curr);
            curr = curr->left;
        } else {
            curr = stack.top();
            stack.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
    }
    return result;
}

int main() {
    // Example Tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> inorder = inorderTraversalIterative(root);
    
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
