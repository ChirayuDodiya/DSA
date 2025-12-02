#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 1. Preorder Traversal

// Recursive Approach
std::vector<int> preorderTraversalRecursive(TreeNode* root) {
    std::vector<int> result;
    if (root) {
        result.push_back(root->val);
        std::vector<int> leftResult = preorderTraversalRecursive(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        std::vector<int> rightResult = preorderTraversalRecursive(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
    }
    return result;
}

// Iterative Approach
std::vector<int> preorderTraversalIterative(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::stack<TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode* node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if (node->right) {
            stack.push(node->right);
        }
        if (node->left) {
            stack.push(node->left);
        }
    }
    return result;
}

// 2. Inorder Traversal

// Recursive Approach
std::vector<int> inorderTraversalRecursive(TreeNode* root) {
    std::vector<int> result;
    if (root) {
        std::vector<int> leftResult = inorderTraversalRecursive(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.push_back(root->val);
        std::vector<int> rightResult = inorderTraversalRecursive(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
    }
    return result;
}

// Iterative Approach
std::vector<int> inorderTraversalIterative(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::stack<TreeNode*> stack;
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

// 3. Postorder Traversal

// Recursive Approach
std::vector<int> postorderTraversalRecursive(TreeNode* root) {
    std::vector<int> result;
    if (root) {
        std::vector<int> leftResult = postorderTraversalRecursive(root->left);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        std::vector<int> rightResult = postorderTraversalRecursive(root->right);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        result.push_back(root->val);
    }
    return result;
}

// Iterative Approach using 2 stacks
std::vector<int> postorderTraversalIterative(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::stack<TreeNode*> stack1, stack2;
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

// Iterative Approach using 1 stack
std::vector<int> postorderTraversalIterativeSingleStack(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr) return result;

    std::stack<TreeNode*> stack;
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
            curr = curr->right; //and go to right subtree
        } else {
            // Otherwise, visit the node and update prev
            result.push_back(curr->val);
            prev = curr;
            curr = nullptr; // Move to the next node
        }
    }
    return result;
}

// 4. Level Order Traversal (Breadth-First Search)
std::vector<std::vector<int>> levelOrderTraversal(TreeNode* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;
    std::queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int levelSize = queue.size();
        std::vector<int> currentLevel;
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
    // Example usage:
    //      1
    //    /   \
    //   2     3
    //  / \   / \
    // 4   5 6   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    std::cout << "Preorder Traversal (Recursive): ";
    std::vector<int> preorderRec = preorderTraversalRecursive(root);
    for (int val : preorderRec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Preorder Traversal (Iterative): ";
    std::vector<int> preorderIter = preorderTraversalIterative(root);
    for (int val : preorderIter) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Inorder Traversal (Recursive): ";
    std::vector<int> inorderRec = inorderTraversalRecursive(root);
    for (int val : inorderRec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Inorder Traversal (Iterative): ";
    std::vector<int> inorderIter = inorderTraversalIterative(root);
    for (int val : inorderIter) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Postorder Traversal (Recursive): ";
    std::vector<int> postorderRec = postorderTraversalRecursive(root);
    for (int val : postorderRec) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Postorder Traversal (Iterative - 2 Stacks): ";
    std::vector<int> postorderIter = postorderTraversalIterative(root);
    for (int val : postorderIter) std::cout << val << " ";
    std::cout << std::endl;

    std::cout << "Postorder Traversal (Iterative - 1 Stack): ";
    std::vector<int> postorderIterSingleStack = postorderTraversalIterativeSingleStack(root);
    for (int val : postorderIterSingleStack) std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "Level Order Traversal: " << std::endl;
    std::vector<std::vector<int>> levelOrder = levelOrderTraversal(root);
    for (const auto& level : levelOrder) {
        for (int val : level) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Remember to free the allocated memory to prevent memory leaks, if needed
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
