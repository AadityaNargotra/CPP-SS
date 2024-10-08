/*
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/
94. Binary Tree Inorder Traversal
Given the root of a binary tree, return the inorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
 
Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

void inorder(TreeNode *root,vector<int> &res){
    if(root==NULL) return;
    inorder(root->left,res);
    res.push_back(root->val);
    inorder(root->right,res);
}

vector<int> inorderTraversal(TreeNode *root)
{   vector<int> res;
    inorder(root,res);
    return res;
}
};

int main(){
    return 0;
}