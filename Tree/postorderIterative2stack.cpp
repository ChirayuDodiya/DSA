#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative Approach using 2 stacks
vector<int> postorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (!root) return result;
    stack<TreeNode*> stack1, stack2;
    stack1.push(root);

    while (!stack1.empty()) {
        TreeNode* node = stack1.top();
        stack1.pop();
        stack2.push(node);
        if (node->left) {
            stack1.push(node->left);
        }
        if (node->right) {
            stack1.push(node->right);
        }
    }
    while (!stack2.empty()) {
        result.push_back(stack2.top()->val);
        stack2.pop();
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

    vector<int> postorder = postorderTraversalIterative(root);
    
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
