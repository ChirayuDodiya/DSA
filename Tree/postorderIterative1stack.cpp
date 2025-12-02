#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> postorderTraversalIterativeSingleStack(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;

    stack<TreeNode*> stack;
    TreeNode* curr = root;
    TreeNode* prev = nullptr; // Keep track of the previously visited node

    while (curr != nullptr || !stack.empty()) {
        // Go to the leftmost leaf
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->left;
        }

        // Get the top node from the stack
        curr = stack.top();
        stack.pop();

        // If the right child exists and has not been visited, go to the right child
        if (curr->right != nullptr && curr->right != prev) {
            stack.push(curr); // Push the current node back to the stack
            curr = curr->right; // and go to right subtree
        } else {
            // Otherwise, visit the node and update prev
            result.push_back(curr->val);
            prev = curr;
            curr = nullptr; // Move to the next node
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

    vector<int> postorder = postorderTraversalIterativeSingleStack(root);
    
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
