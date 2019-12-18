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
            case TreeGraphSolutionEnum::BSTLowestComAnc:
            {
                TreeNode *root = new TreeNode(6);
                root->left = new TreeNode(2);
                root->right = new TreeNode(8);
                root->left->left = new TreeNode(0);
                root->left->right = new TreeNode(4);
                root->left->right->left = new TreeNode(3);
                root->left->right->right = new TreeNode(5);
                root->right->left = new TreeNode(7);
                root->right->right = new TreeNode(9);
                TreeNode *p = root->left->left;
                TreeNode *q = root->left->right->right;
                cout << BSTLowestCommonAncestor(root, p, q)->val << endl;
                break;
            }
            case TreeGraphSolutionEnum::NormalLowestComAc:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(5);
                root->right = new TreeNode(1);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(0);
                root->right->right = new TreeNode(8);
                TreeNode *p = root->left;
                TreeNode *q = root->left->right->right;
                cout << NoramlTreeLowestCommonAncestor(root, p, q)->val << endl;
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

    TreeNode* TreeSolution::BSTLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root)
        {
            // 由于是二叉搜索树，那么最近公共祖先的值一定是介于p.val和q.val之间
            // 要注意p或q本身就是最近公共祖先的情况
            if (root->val > p->val && root->val > q->val)
            {
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val)
            {
                root = root->right;
            }
            else
            {
                return root;
            }
        }
        return root;
    }

    TreeNode* TreeSolution::NoramlTreeLowestCommonAncestorMethod2(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        TreeNode* left = NoramlTreeLowestCommonAncestorMethod2(root->left, p, q);
        TreeNode* right = NoramlTreeLowestCommonAncestorMethod2(root->right, p, q);

        if (left == NULL)
        {
            return right;
        }
        else if (right == NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }

    TreeNode* TreeSolution::NoramlTreeLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        while (root)
        {
            // 要注意p或q本身就是最近公共祖先的情况
            if (root == p || root == q)
            {
                return root;
            }
            TreeNode *leftResult = FindPorQ(root->left, p, q);
            TreeNode *rightResult = FindPorQ(root->right, p, q);
            // 只有最近公共祖先才能在左右子树同时返回不为null  
            if (leftResult != NULL && rightResult != NULL)
            {
                return root;
            }

            if (leftResult == NULL)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }

        return root;
    }
    // 找寻root下面的子树是否包含P或Q，如果找到则返回最先找到的那个
    TreeNode* TreeSolution::FindPorQ(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == NULL || root == p || root == q)
        {
            return root;
        }
        // 先找左边，如果左边找到了就可以直接返回了
        TreeNode *leftResult = FindPorQ(root->left, p, q);
        if (leftResult != NULL)
        {
            return leftResult;
        }
        else
        {
            return FindPorQ(root->right, p, q);
        }

    }
}