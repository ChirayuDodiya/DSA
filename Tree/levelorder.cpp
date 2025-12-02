#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 4. Level Order Traversal (Breadth-First Search)
vector<vector<int>> levelOrderTraversal(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int levelSize = queue.size();
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = queue.front();
            queue.pop();
            currentLevel.push_back(node->val);
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
        result.push_back(currentLevel);
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

    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    
    for (int i = 0; i < levelOrder.size(); i++) {
        cout << "Level " << i + 1 << ": ";
        for (int val : levelOrder[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
