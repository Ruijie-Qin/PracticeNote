#include <cstddef>
#include <vector>
#include <string>
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
        TreeTrie,
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

    class TrieNode
    {
    public:
        char val;
        bool isWord = false;
        TrieNode* children[26] = {nullptr};

        TrieNode(char c);
    };

    class Trie {
    public:
        TrieNode *root;
        /** Initialize your data structure here. */
        Trie();
        
        /** Inserts a word into the trie. */
        void insert(string word);
        
        /** Returns if the word is in the trie. */
        bool search(string word);
        
        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix);
    };
}