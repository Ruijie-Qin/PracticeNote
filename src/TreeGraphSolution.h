#include <cstddef>
#include <vector>
#include <set>
#include <string>
#include <iostream>
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
        WordSearch1,
        WordSearch2,
    };

    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    class TrieNode
    {
    public:
        bool isWord = false;
        TrieNode* children[26] = {nullptr};
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
        /// 79. Word Search
        bool exist(vector<vector<char>>& board, string word);
        /// 212. Word Search II
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
    private:
        TreeNode *validBstPreNode;
        // 方法一：中序遍历
        bool validBSTHelper(TreeNode* root);
        // 方法二：递归
        bool validBSTHelper2(TreeNode* root, long min, long max);
        // NoramlTreeLowestCommonAncestorHelp
        TreeNode* FindPorQ(TreeNode* root, TreeNode* p, TreeNode* q);
        // wordSearch
        bool wordSearchDfs(vector<vector<char>>& board, int i, int j, const string &word, int index);
        // wordSearch2
        void wordSearch2Dfs(vector<vector<char>>& board, int i, int j, TrieNode *curNode, set<string> &result, string curString);
    };

    
}