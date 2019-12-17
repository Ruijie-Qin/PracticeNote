#include "TreeGraphSolution.h"
#include <limits>
#include <iostream>
using namespace std;

namespace Phoenix
{
    void TreeSolution::RunTestCase(TreeGraphSolutionEnum solutionType)
    {
        switch (solutionType)
        {
            case TreeGraphSolutionEnum::ValidBST:
            {
                TreeNode *root = new TreeNode(1);
                root->left = new TreeNode(-1);
                root->right = new TreeNode(3);
                root->right->left = new TreeNode(0);
                root->right->right = new TreeNode(4);
                cout << isValidBST(root) << endl;
                break;
            }
            default:
                break;
        }
    }

    bool TreeSolution::isValidBST(TreeNode* root)
    {
        validBstPreNode = NULL;
        // return validBSTHelper(root);
        return validBSTHelper2(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }

    bool TreeSolution::validBSTHelper(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (validBSTHelper(root->left) == false)
        {
            return false;
        }
        // 二叉搜索树要严格小于/大于才行，不能等于
        if (validBstPreNode != NULL && validBstPreNode->val >= root->val)
        {
            return false;
        }
        validBstPreNode = root;
        return validBSTHelper(root->right);
    }

     bool TreeSolution::validBSTHelper2(TreeNode* root, long min, long max)
     {
         if (root == NULL)
         {
             return true;
         }
         if (root->val <= min || root->val >= max) 
         {
             return false;
         }

         return validBSTHelper2(root->left, min, root->val) && validBSTHelper2(root->right, root->val, max);
     }
}