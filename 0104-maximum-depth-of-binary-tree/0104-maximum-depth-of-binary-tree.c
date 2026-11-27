/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    // For tree traversal questions always think in terms of reccursive operations
    if(root == NULL){
        return 0;
    }

    int leftHt = maxDepth(root->left);
    int rightHt = maxDepth(root->right);

    return (leftHt > rightHt) ? leftHt+1 : rightHt+1;
}