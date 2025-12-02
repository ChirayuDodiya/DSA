#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> preorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    if (root) {
        result.push_back(root->val);
        vector<int> leftResult = preorderTraversalRecursive(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        vector<int> rightResult = preorderTraversalRecursive(root->right);
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

    vector<int> preorder = preorderTraversalRecursive(root);

    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
