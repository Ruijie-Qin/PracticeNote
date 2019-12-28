#include "TreeGraphSolution.h"
#include <limits>
#include <iostream>
#include <queue>
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
            case TreeGraphSolutionEnum::LevelOrder:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                vector<vector<int>> result = levelOrder(root);
                for (int i = 0; i < result.size(); i++)
                {
                    cout << "[";
                    for (int j = 0; j < result[i].size(); j++)
                    {
                        cout << result[i][j] << ",";
                    }
                    cout << "]" << endl;
                }
                break;
            }
            case TreeGraphSolutionEnum::MaxDepth:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                int result = maxDepth(root);
                cout << result << endl;
                break;
            }
            case TreeGraphSolutionEnum::MinDepth:
            {
                TreeNode *root = new TreeNode(3);
                root->left = new TreeNode(9);
                root->right = new TreeNode(20);
                root->left->left = new TreeNode(6);
                root->left->right = new TreeNode(2);
                root->left->right->left = new TreeNode(7);
                root->left->right->right = new TreeNode(4);
                root->right->left = new TreeNode(15);
                root->right->right = new TreeNode(7);
                int result = minDepth(root);
                cout << result << endl;
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

    // 使用BFS计算结果，还有另一种方法是使用DFS（纵向填充result数组）
    vector<vector<int>> TreeSolution::levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        while (!helpQueue.empty())
        {
            int size = helpQueue.size();
            vector<int> temp;
            // 这里可以通过当前队列的数量来判断这一层有多少个节点
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = helpQueue.front();
                temp.push_back(curNode->val);
                helpQueue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    helpQueue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    helpQueue.push(curNode->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }

    int TreeSolution::maxDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int maxDepth = 0;
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        // BFS遍历完整，找到最深的一层
        while (!helpQueue.empty())
        {
            maxDepth++;
            int size = helpQueue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = helpQueue.front();
                helpQueue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    helpQueue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    helpQueue.push(curNode->right);
                }
            }
        }
        return maxDepth;
    }

    int TreeSolution::minDepth(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int minDepth = 0;
        queue<TreeNode*> bfsQue;
        bfsQue.push(root);
        // BFS遍历，找到最早的叶子节点返回就可以了
        while (!bfsQue.empty())
        {
            minDepth++;
            int size = bfsQue.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* curNode = bfsQue.front();
                if (curNode->left == nullptr && curNode->right == nullptr)
                {
                    return minDepth;
                }
                bfsQue.pop();
                // 子节点入队
                if (curNode->left != nullptr)
                {
                    bfsQue.push(curNode->left);
                }
                if (curNode->right != nullptr)
                {
                    bfsQue.push(curNode->right);
                }
            }
           
        }
        return minDepth;
    }
}