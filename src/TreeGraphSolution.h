#include <cstddef>

namespace Phoenix
{
    enum TreeGraphSolutionEnum
    {
        ValidBST = 1,
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
    private:
        TreeNode *validBstPreNode;
        // 方法一：中序遍历
        bool validBSTHelper(TreeNode* root);
        // 方法二：递归
        bool validBSTHelper2(TreeNode* root, long min, long max);
    };
}