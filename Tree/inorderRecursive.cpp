#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    if (root) {
        vector<int> leftResult = inorderTraversalRecursive(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.push_back(root->val);
        vector<int> rightResult = inorderTraversalRecursive(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
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

    vector<int> inorder = inorderTraversalRecursive(root);
    
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
