#include <cstddef>
#include <vector>
using namespace std;

namespace Phoenix
{
    enum TreeGraphSolutionEnum
    {
        ValidBST = 1,
        BSTLowestComAnc,
        NormalLowestComAc,
        LevelOrder,
        MaxDepth,
        MinDepth,
    };

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class TreeSolution
    {
    public:
        /// 执行测试案例
        void RunTestCase(TreeGraphSolutionEnum solutionType);
        /// Validate Binary Search Tree
        bool isValidBST(TreeNode* root);
        /// Lowest Common Ancestor of a Binary Search Tree
        TreeNode* BSTLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
        /// Lowest Common Ancestor of a Binary Tree
        TreeNode* NoramlTreeLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
        TreeNode* NoramlTreeLowestCommonAncestorMethod2(TreeNode* root, TreeNode* p, TreeNode* q);
        /// 102: Binary Tree Level Order Traversal
        vector<vector<int>> levelOrder(TreeNode* root);
        /// 104: Maximum Depth of Binary Tree
        int maxDepth(TreeNode* root);
        /// 111: Minimum Depth of Binary Tree
        int minDepth(TreeNode* root);
    private:
        TreeNode *validBstPreNode;
        // 方法一：中序遍历
        bool validBSTHelper(TreeNode* root);
        // 方法二：递归
        bool validBSTHelper2(TreeNode* root, long min, long max);
        // NoramlTreeLowestCommonAncestorHelp
        TreeNode* FindPorQ(TreeNode* root, TreeNode* p, TreeNode* q);
    };
}